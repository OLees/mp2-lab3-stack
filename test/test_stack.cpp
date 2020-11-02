#include "ustack.h"

#include <gtest.h>

TEST(TStack, can_create_stack) 
{
	ASSERT_NO_THROW(Stack<int> S);
};

TEST(TStack, can_create_sized_stack)
{
	ASSERT_NO_THROW(Stack<int> S(5));
};

TEST(TStack, cant_create_negative_sized_stack)
{
	ASSERT_ANY_THROW(Stack<int> S(-1));
};

TEST(TStack, can_push_to_stack)
{
	Stack<int> S(5);
	ASSERT_NO_THROW(S.push(2));
};

TEST(TStack, can_get_top)
{
	Stack<int> S(3);
	S.push(0);
	S.push(1);
	S.push(2);
	EXPECT_EQ(2, S.Top());
};

TEST(TStack, can_pop_from_stack)
{
	Stack<int> S(5);
	ASSERT_NO_THROW(S.pop());
};

TEST(TStack, cant_pop_from_empty_stack)
{
	Stack<int> S;
	ASSERT_ANY_THROW(S.pop());
};

TEST(TStack, can_create_empty_stack)
{
	Stack<int> S;
	EXPECT_EQ(1, S.IsEmpty());
};

TEST(TStack, cant_fill_stack_because_we_resize_it_every_push)
{
	Stack<int> S(4);
	S.push(1);
	S.push(2);
	S.push(3);
	S.push(4);
	EXPECT_EQ(1, S.IsFull());
};
