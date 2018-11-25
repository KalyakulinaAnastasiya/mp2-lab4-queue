#include "procc.h"
#include <gtest.h>
TEST(TQueue, can_create_queue)
{
	ASSERT_NO_THROW(TStack<int> p(5));
}

TEST(TQueue, cant_create_queue_too_large_length)
{
	ASSERT_ANY_THROW(TStack<int>q(MaxStackSize + 1));
}
TEST(TQueue, can_create_queue_with_negativ_length)
{
	ASSERT_ANY_THROW(TStack<int>q(-1));
}
TEST(TQueue, check_IsEmpty_with_empty_queue)
{
	TStack<int> q(5);
	EXPECT_EQ(true, q.IsEmpty());
}
TEST(TQueue, check_IsEmpty_with_not_empty_queue)
{
	TStack<int> q(5);
	q.Push(2);
	EXPECT_EQ(false, q.IsEmpty());
}

TEST(TQueue, check_IsFull_with_not_full_queue)
{
	TStack<int> q(5);
	q.Push(2);
	EXPECT_EQ(false, q.IsFull());
}
TEST(TQueue, throws_when_Pop_queue_IsEmty)
{
	TStack<int> st(5);
	ASSERT_ANY_THROW(st.Back());
}



