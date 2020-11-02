#include "ustack.h"

#include <gtest.h>

TEST(TQueue, can_create_queue)
{
	ASSERT_NO_THROW(Queue<int> S);
};

TEST(TQueue, can_create_sized_queue)
{
	ASSERT_NO_THROW(Queue<int> Q(5));
};

TEST(TQueue, can_push_to_queue)
{
	Queue<int> Q(5);
	ASSERT_NO_THROW(Q.push(5));
};

TEST(TQueue, can_get_start)
{
	Queue<int> Q(3);
	Q.push(1);
	Q.push(2);
	Q.push(3);
	EXPECT_EQ(1, Q.front());
};

TEST(TQueue, can_get_end)
{
	Queue<int> Q(3);


};

TEST(TQueue, can_pop_from_stack)
{
	Queue<int> Q(5);
	
};

TEST(TQueue, cant_pop_from_empty_stack)
{
	Queue<int> Q;

};

TEST(TQueue, can_create_empty_stack)
{
	Queue<int> S;
	
};

