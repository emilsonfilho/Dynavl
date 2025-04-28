#include "Commander/Commands/CreateCommand.hpp"
#include "Commander/Contexts/CreateCommandContext.hpp"
#include "../def/Repository.hpp"
#include "Set/Set.hpp"

#include <gtest/gtest.h>
#include <queue>
#include <vector>
#include <string>

using std::queue;
using std::vector;
using std::string;

// Helper to capture stdout from execute()
static string captureExecute(CreateCommand& cmd, CreateCommandContext* ctx) {
    testing::internal::CaptureStdout();
    cmd.execute(ctx);
    return testing::internal::GetCapturedStdout();
}

TEST(CreateCommandTest, ExecuteWithEmptyInitialData) {
    vector<SetInfo> repo;
    queue<int> data;  // empty
    CreateCommandContext ctx(repo, data, "test-origin");
    CreateCommand cmd("create", "desc");

    string output = captureExecute(cmd, &ctx);

    // Should have added one SetInfo at position 0
    ASSERT_EQ(repo.size(), 1u);
    EXPECT_EQ(repo[0].origin, "gerado por linha de comando");
    // The stored Set* must not be null and must be empty
    EXPECT_NE(repo[0].set, nullptr);
    EXPECT_EQ(repo[0].set->size(), 0u);

    // Context's initialData should now be empty
    EXPECT_TRUE(ctx.initialData.empty());

    // Output message should mention position 0
    EXPECT_EQ(output, "Conjunto adicionado com sucesso na posição 0\n");
}

TEST(CreateCommandTest, ExecuteWithSomeInitialData) {
    vector<SetInfo> repo;
    queue<int> data;
    data.push(10);
    data.push(20);
    data.push(10);  // duplicate to see if Set ignores it

    CreateCommandContext ctx(repo, data, "cli");
    CreateCommand cmd("create", "desc");

    string output = captureExecute(cmd, &ctx);

    // One new entry at position 0
    ASSERT_EQ(repo.size(), 1u);
    Set* result = repo[0].set;
    ASSERT_NE(result, nullptr);

    // Should contain 10 and 20 only once each
    EXPECT_TRUE(result->contains(10));
    EXPECT_TRUE(result->contains(20));
    EXPECT_EQ(result->size(), 2u);

    // Context queue emptied
    EXPECT_TRUE(ctx.initialData.empty());

    // Output mentions correct position
    EXPECT_EQ(output, "Conjunto adicionado com sucesso na posição 0\n");
}

TEST(CreateCommandTest, ExecuteAppendsToExistingRepository) {
    vector<SetInfo> repo;
    // Pre-populate repo with two dummy sets
    repo.emplace_back(new Set(), "old1");
    repo.emplace_back(new Set(), "old2");

    queue<int> data;
    data.push(5);

    CreateCommandContext ctx(repo, data, "cli2");
    CreateCommand cmd("create", "desc2");

    string output = captureExecute(cmd, &ctx);

    // Should now have size 3, new at index 2
    ASSERT_EQ(repo.size(), 3u);
    EXPECT_EQ(repo[2].origin, "gerado por linha de comando");
    EXPECT_TRUE(repo[2].set->contains(5));
    EXPECT_EQ(output, "Conjunto adicionado com sucesso na posição 2\n");
}

TEST(CreateCommandTest, MultipleExecuteCallsAreIndependent) {
    vector<SetInfo> repo;
    queue<int> data1;
    data1.push(1);
    CreateCommandContext ctx1(repo, data1, "o1");

    CreateCommand cmd("create", "desc");

    // First execution
    string out1 = captureExecute(cmd, &ctx1);
    EXPECT_EQ(repo.size(), 1u);
    EXPECT_EQ(out1, "Conjunto adicionado com sucesso na posição 0\n");

    // Prepare a second context with different data
    queue<int> data2;
    data2.push(2);
    data2.push(3);
    CreateCommandContext ctx2(repo, data2, "o2");

    // Second execution appends to position 1
    string out2 = captureExecute(cmd, &ctx2);
    EXPECT_EQ(repo.size(), 2u);
    EXPECT_TRUE(repo[1].set->contains(2));
    EXPECT_TRUE(repo[1].set->contains(3));
    EXPECT_EQ(out2, "Conjunto adicionado com sucesso na posição 1\n");
}
