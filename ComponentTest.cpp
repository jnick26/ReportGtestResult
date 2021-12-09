#include <gmock/gmock.h>

using testing::Eq;

namespace {
int add(int a, int b) { return a + b; }
} // namespace

TEST(ComponentTest, Basic) { EXPECT_THAT(add(10, 20), Eq(30)); }

TEST(ComponentTest, FailingBasic) { EXPECT_THAT(add(20, 20), Eq(40)); }