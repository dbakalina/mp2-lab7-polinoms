#include"gtest.h"
#include<algorithm>
#include "../Polinoms/List.h"


//Мономы
TEST(TMonom, can_create_monom)
{
	ASSERT_NO_THROW(TMonom m);
}

TEST(TMonom, monom_fields_are_initialized_by_default)
{
	TMonom m;
	int error = 0;
	if (m.x != 0 || m.y != 0 || m.z != 0 || m.coeff != 1.0)
		error++;
	EXPECT_EQ(0, error);
}


TEST(TMonom, can_compare_the_monoms)
{
	TMonom m1(1, 1, 1, 1.0), m2(1, 2, 1, 1.0);
	EXPECT_EQ(true, m1 < m2);
	EXPECT_EQ(true, m2 > m1);
	m1.y = 2;
	EXPECT_EQ(true, m1 == m2);
}

TEST(TMonom, monom_can_be_assigned_to)
{
	TMonom m1, m2(1, 2, 3, 4.0);
	m1 = m2;
	int error = 0;
	if (m1.x != 1 || m1.y != 2 || m1.z != 3 || m1.coeff != 4.0)
		error++;
	EXPECT_EQ(0, error);
}

TEST(TMonom, can_multiplying_monoms_by_each_other)
{
	TMonom m1(1, 2, 3, 4.0), m2(4, 3, 2, 1.0);
	m1 = m1 * m2;
	int error = 0;
	if (m1.x != 5 || m1.y != 5 || m1.z != 5 || m1.coeff != 4.0)
		error++;
	EXPECT_EQ(0, error);
}

TEST(TMonom, monoms_can_be_multiplied_by_a_number)
{
	TMonom m(1, 2, 3, 4.0);
	m = m * 5.0;
	int error = 0;
	if (m.x != 1 || m.y != 2 || m.z != 3 || m.coeff != 20.0)
		error++;
	EXPECT_EQ(0, error);
}

//Список
TEST(TList, can_create_list)
{
	ASSERT_NO_THROW(TList<int> l);
}

TEST(TList, can_add_an_elem_to_the_top_of_the_empty_list)
{
	TList<int> l;
	ASSERT_NO_THROW(l.InsFirst(5));
}

TEST(TList, can_copy_list)
{
	TList<int>l;
	l.InsFirst(5);
	ASSERT_NO_THROW(TList<int> copy(l));
}

TEST(TList, can_add_an_elem_to_the_top_of_the_no_empty_list)
{
	TList<int> l;
	l.InsFirst(5);
	ASSERT_NO_THROW(l.InsFirst(5));
}

TEST(TList, can_add_an_elem_to_the_end_of_the_empty_list)
{
	TList<int> l;
	ASSERT_NO_THROW(l.InsLast(5));
}

TEST(TList, can_add_an_elem_to_the_end_of_the_no_empty_list)
{
	TList<int> l;
	l.InsFirst(5);
	ASSERT_NO_THROW(l.InsLast(5));
}

TEST(TList, can_del_an_elem_to_the_top_of_the_no_empty_list)
{
	TList<int> l;
	l.InsFirst(5);
	ASSERT_NO_THROW(l.DelFirst());
}

TEST(TList, cant_delete_an_elem_from_an_empty_list)
{
	TList<int> l;
	l.InsLast(5);
	l.DelFirst();
	ASSERT_ANY_THROW(l.DelFirst());
}

//Полиномы
TEST(TPolinom, can_create_polinom)
{
	ASSERT_NO_THROW(TPolinom l);
}

TEST(TPolinom, can_copy_polinom)
{
	TPolinom l;
	TMonom m(2, 4, 8, 3.14);
	l.InsMonom(m);
	ASSERT_NO_THROW(TPolinom p(l));
}

TEST(TPolinom, the_copied_polinom_has_its_own_memory)
{
	TPolinom l;
	TMonom m(2, 4, 8, 3.14);
	l.InsMonom(m);
	TPolinom p(l);
	p.DelFirst();
	EXPECT_EQ(1, l.Get_Size());
}

TEST(TPolinom, can_insert_monom)
{
	TPolinom p;
	TMonom m;
	ASSERT_NO_THROW(p.InsMonom(m));
}

TEST(TPolinom, adding_a_similar_monomial_does_not_change_the_size_of_the_polynomial)
{
	TPolinom p;
	TMonom m1(1, 2, 3, 4.0), m2(1, 2, 3, 2.0);
	p.InsMonom(m1);
	int size = p.Get_Size();
	p.InsMonom(m2);
	EXPECT_EQ(size, p.Get_Size());
}

TEST(TPolinom, adding_a_monomial_with_opposite_sign_to_an_existing_monomial_removes_the_given_monomial_from_the_list)
{
	TPolinom p;
	TMonom m1(1, 2, 3, 4.0), m2(1, 2, 3, -4.0);
	p.InsMonom(m1);
	int size = p.Get_Size();
	p.InsMonom(m2);
	EXPECT_EQ(size - 1, p.Get_Size());
}

TEST(TPolinom, can_compare_empty_polinom)
{
	TPolinom p1, p2, p3;
	TMonom m;
	p1.InsMonom(m);
	m.x = 5;
	p2.InsMonom(m);
	m.y = 5;
	p3.InsMonom(m);
	ASSERT_NO_THROW(p1 = p2 = p3);
}

TEST(TPolinom, can_compare_no_empty_polinom_the_different_sizes_)
{
	TPolinom p1, p2;
	TMonom m1, m2(1, 2, 3, 4.0);
	p2.InsMonom(m1);
	p2.InsMonom(m2);
	ASSERT_NO_THROW(p1 = p2);
	TMonom m3(2, 4, 6, 1.0), m4(0, 9, 0, 5.0);
	TPolinom p3;
	p3.InsMonom(m3);
	p2.InsMonom(m4);
	ASSERT_NO_THROW(p2 = p3);
}

TEST(TPolinom, can_multiply_a_polinom_by_a_number)
{
	TPolinom p, res;
	TMonom m;
	p.InsMonom(m);
	ASSERT_NO_THROW(res = p * 5);
}

TEST(TPolinom, multiplying_a_polynomial_by_a_number_does_not_change_its_size)
{
	TPolinom p, res;
	TMonom m;
	p.InsMonom(m);
	int size = p.Get_Size();
	res = p * 5;
	EXPECT_EQ(size, res.Get_Size());
}

TEST(TPolinom, multiplying_a_polynomial_by_zero_makes_the_polynomial_empty)
{
	TPolinom p, res;
	TMonom m;
	p.InsMonom(m);
	res.InsMonom(m);
	res = p * 0;
	EXPECT_EQ(0, res.Get_Size());
}

TEST(TPolinom, can_multiply_a_polinom_by_a_monom)
{
	TPolinom p, res;
	TMonom m, m1(1, 0, 2, 4.0);
	p.InsMonom(m);
	ASSERT_NO_THROW(res = p * m1);
}

TEST(TPolinom, multiplying_a_polynomial_by_a_nonzero_number_does_not_change_its_size)
{
	TPolinom p, res;
	TMonom m;
	p.InsMonom(m);
	TMonom m1(4, 3, 2, 1.0);
	int size = p.Get_Size();
	res = p * m1;
	EXPECT_EQ(size, res.Get_Size());
}

TEST(TPolinom, multiplying_a_polynomial_by_a_zero_number_change_its_size)
{
	TPolinom p, res;
	TMonom m;
	p.InsMonom(m);
	res.InsMonom(m);
	TMonom m1(4, 3, 2, 0.0);
	res = p * m1;
	EXPECT_EQ(0, res.Get_Size());
}

TEST(TPolinom, can_add_up_an_emty_polinom_by_a_no_empty_polinom)
{
	TPolinom p1, p2, res;
	TMonom m;
	p2.InsMonom(m);
	ASSERT_NO_THROW(res = p1 + p2);
	ASSERT_NO_THROW(p1 += p2);
}

TEST(TPolinom, can_add_up_a_no_empty_polinom_by_a_no_empty_polinom)
{
	TPolinom p1, p2, res;
	TMonom m1, m2(1, 2, 3, 4.0);
	p1.InsMonom(m1);
	p2.InsMonom(m2);
	ASSERT_NO_THROW(res = p1 + p2);
	ASSERT_NO_THROW(p1 += p2);
}

TEST(TPolinom, when_adding_polynomials_the_coefficients_of_identical_monomials_add_up)
{
	TPolinom p1, p2, res;
	TMonom m1, m2(1, 2, 3, 4.0), m3(1, 2, 3, 3.0);
	p1.InsMonom(m1);
	p1.InsMonom(m2);
	p2.InsMonom(m3);
	res = p1 + p2;
	EXPECT_EQ(res.Get_Size(), 2);
	p1 += p2;
	EXPECT_EQ(p1.Get_Size(), 2);
}

TEST(TPolinom, when_adding_polynomials_monoms_with_opposite_coefficients_are_removed)
{
	TPolinom p1, p2, res;
	TMonom m1, m2(1, 2, 3, 4.0), m3(1, 2, 3, -4.0);
	p1.InsMonom(m1);
	p1.InsMonom(m2);
	p2.InsMonom(m3);
	res = p1 + p2;
	EXPECT_EQ(res.Get_Size(), 1);
	p1 += p2;
	EXPECT_EQ(p1.Get_Size(), 1);
}