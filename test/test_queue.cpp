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

TEST(TQueue, can_create_queue_with_max_size)
{
	ASSERT_NO_THROW(Queue<int> Q(MAX_SIZE));
}

TEST(TQueue, cant_create_queue_with_negative_length)
{
	ASSERT_ANY_THROW(Queue<int> Q(-5));
}

TEST(TQueue, cant_create_too_large_queue)
{
	ASSERT_ANY_THROW(Queue<int> Q(MAX_SIZE + 1));
}

TEST(TQueue, can_create_copied_queue)
{
	Queue<int> Q1(3);
	ASSERT_NO_THROW(Queue<int> Q2(Q1));
}

TEST(TQueue, copied_queue_is_equal_to_source_one)
{
	Queue<int> Q1(3);
	Queue<int> Q2(Q1);
	EXPECT_EQ(Q1, Q2);
}

TEST(TQueue, queues_with_different_sizes_are_not_equal)
{
	Queue<int> Q1(3);
	Q1.push(1);
	Q1.push(1);
	Queue<int> Q2(4);
	Q2.push(1);
	int res = Q1 == Q2;
	EXPECT_EQ(0, res);
}

TEST(TQueue, can_push_to_queue)
{
	Queue<int> Q(5);
	ASSERT_NO_THROW(Q.push(5));
};

TEST(TQueue, can_push_to_filled_queue)
{
	Queue<int> Q(3);
	Q.push(1);
	Q.push(1);
	Q.push(1);
	ASSERT_NO_THROW(Q.push(5));
};

TEST(TQueue, can_pop_elem)
{
	Queue<int> Q(2);
	Q.push(3);
	Q.push(5);
	ASSERT_NO_THROW(Q.pop());
}

TEST(TQueue, cant_pop_from_empty_queue)
{
	Queue<int> Q;
	ASSERT_ANY_THROW(Q.pop());
};

TEST(TQueue, can_get_start)
{
	Queue<int> Q(3);
	Q.push(5);
	EXPECT_EQ(5, Q.front());
};

TEST(TQueue, can_get_end)
{
	Queue<int> Q(3);
	Q.push(1);
	Q.push(2);
	Q.push(3);
	EXPECT_EQ(3, Q.back());
};

TEST(TQueue, cant_get_start_elem_of_empty_queue)
{
	Queue<int> Q;
	ASSERT_ANY_THROW(Q.front());
}

TEST(TQueue, cant_get_end_elem_of_empty_queue)
{
	Queue<int> Q;
	ASSERT_ANY_THROW(Q.back());
}

TEST(TQueue, can_detect_empty_queue)
{
	Queue<int> Q;
	EXPECT_EQ(true, Q.empty());
}

TEST(TQueue, can_detect_not_empty_queue)
{
	Queue<int> Q(3);
	Q.push(1);
	Q.push(3);
	Q.push(4);
	EXPECT_EQ(0, Q.empty());
}

TEST(TQueue, can_detect_full_queue_when_start_is_null_elem)
{
	Queue<int> Q(2);
	//Q.push(1);
	//Q.push(3);
	//Q.push(5);
	EXPECT_EQ(1, Q.IsFull());
}

TEST(TQueue, can_resize_queue)
{
	Queue<int> Q;
	ASSERT_NO_THROW(Q.Resize(4));
}

TEST(TQueue, can_push_elem_to_full_queue)
{
	Queue<int> Q(2);
	Q.push(3);
	Q.push(5);
	ASSERT_NO_THROW(Q.push(7));
}

TEST(TQueue, push_changes_end_pointer)
{
	Queue<int> Q(2);
	Q.push(3);
	Q.push(5);
	Q.push(7);
	EXPECT_EQ(7, Q.back());
}

TEST(TQueue, push_in_null_index_if_queue_is_not_full_chandes_end_pointer)
{
	Queue<int> Q(2);
	Q.push(1);
	Q.push(3);
	Q.pop();
	Q.push(5);
	Q.push(7);
	EXPECT_EQ(7, Q.back());
}

TEST(TQueue, pop_doesnt_change_start_pointer)
{
	Queue<int> Q(2);
	Q.push(3);
	Q.push(5);
	Q.pop();
	EXPECT_EQ(5, Q.front());
}

TEST(TQueue, can_push_and_pop_multiple_times)
{
	Queue<int> Q(5);

	Q.push(1);//1
	Q.push(2);//21
	Q.push(3);//321

	Q.pop();//32
	Q.pop();//3

	Q.push(4);//43
	Q.push(5);//543
	Q.push(6);//6543
	Q.push(7);//76543
	Q.push(8);//876543

	Q.pop();
	//Q.pop();
	//Q.pop();
	//Q.pop();
	//Q.pop();

	EXPECT_EQ(4, Q.front());
}
