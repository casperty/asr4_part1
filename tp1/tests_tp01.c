#include <minunit.h>

#include "tp01.h"

#define T1_MAX_SIZE 128
#define T2_MAX_SIZE (T1_MAX_SIZE*2)
#define MAGIC -1

int t1[T1_MAX_SIZE];
int t2[T2_MAX_SIZE];

/************** Somme *************************/
MU_SETUP(somme){
    int i;
    for (i = 0 ; i < T1_MAX_SIZE ; ++i)
	t1[i] = MAGIC;
    for (i = 0 ; i < T2_MAX_SIZE ; ++i)
	t2[i] = MAGIC;
}
MU_TEAR_DOWN(somme){
}

MU_TEST(somme,somme_normale){
    int i, size = 10;
    for (i = 0 ; i < size ; ++i)
	t1[i] = i;
    MU_ASSERT_EQUAL(somme(t1, size), size*(size-1)/2); /* somme des i pour i de 0 à n = n(n-1)/2 */
}

MU_TEST(somme,somme_zero){
    MU_ASSERT_EQUAL(somme(t1,0),0);
}

MU_TEST(somme,somme_minus){
    MU_ASSERT_EQUAL(somme(t1,-1),0);
}

MU_TEST_SUITE(somme) = {
    MU_ADD_TEST(somme,somme_normale),
    MU_ADD_TEST(somme,somme_zero),
    MU_ADD_TEST(somme,somme_minus),
    MU_TEST_SUITE_END
};

/************** copie *************************/
#define COPIE_LOWER_BOUND 10
MU_SETUP(copie){
    int i;
    for (i = 0 ; i < T2_MAX_SIZE ; ++i)
	t2[i] = MAGIC;
    for (i = 0 ; i < T1_MAX_SIZE ; ++i)
	t1[i] = i;
}
MU_TEAR_DOWN(copie){
}

MU_TEST(copie, copie_normale){
    int *dest = t2 + COPIE_LOWER_BOUND;
    int i;
    MU_ASSERT_LESS(T1_MAX_SIZE, T2_MAX_SIZE-10);
    MU_ASSERT_EQUAL(copie_dans(dest, t1, T1_MAX_SIZE), dest);
    
    /* Assert that lower bound of T2 was not affected */
    for (i = 0 ; i < COPIE_LOWER_BOUND ; ++i)
	MU_ASSERT_EQUAL(t2[i], MAGIC);
    /* Assert that the remainder of t2 was not affected by copy */
    for (i = T1_MAX_SIZE + COPIE_LOWER_BOUND ; i < T2_MAX_SIZE ; ++i)
	MU_ASSERT_EQUAL(t2[i],MAGIC);
}

MU_TEST(copie, copie_zero){
    int i;
    copie_dans(t2,t1,0);
    /* Assert that nothing has been modified in t2 */
    for (i = 0 ; i < T2_MAX_SIZE ; ++i)
	MU_ASSERT_EQUAL(t2[i], MAGIC);
}

MU_TEST(copie, copie_minus){
    int i;
    copie_dans(t2,t1,-1);
    /* Assert that nothing has been modified in t2 */
    for (i = 0 ; i < T2_MAX_SIZE ; ++i)
	MU_ASSERT_EQUAL(t2[i], MAGIC);
}



MU_TEST_SUITE(copie) = {
    MU_ADD_TEST(copie, copie_normale),
    MU_ADD_TEST(copie, copie_zero),
    MU_ADD_TEST(copie, copie_minus),
    MU_TEST_SUITE_END
};


/************************ ajoute_apres **************************/
#define T2_LOWER_BOUND 10
#define DEST_SIZE 10
#define SRC_SIZE 5
MU_SETUP(ajoute_apres){
    int i;
    for (i = 0 ; i < T2_MAX_SIZE ; ++i)
	t2[i] = MAGIC+1;
    for (i = 0 ; i < T1_MAX_SIZE ; ++i)
	t1[i] = MAGIC;
    for (i = 0 ; i < DEST_SIZE ; ++i)
	t2[i+T2_LOWER_BOUND] = i;
    for (i = 0 ; i < SRC_SIZE ; ++i)
	t1[i] = i+DEST_SIZE;
}
MU_TEAR_DOWN(ajoute_apres){
}

MU_TEST(ajoute_apres, normal){
    int *dest = t2 + T2_LOWER_BOUND;
    int i;

    MU_ASSERT_EQUAL(ajoute_apres(dest, DEST_SIZE, t1, SRC_SIZE), dest);
    /* check for out of bounds */
    for (i = 0 ; i < T2_LOWER_BOUND; ++i)
	MU_ASSERT_EQUAL(t2[i], MAGIC+1);
    for (i = T2_LOWER_BOUND + DEST_SIZE + SRC_SIZE ; i < T2_MAX_SIZE ; ++i)
	MU_ASSERT_EQUAL(t2[i], MAGIC+1);

    /* check for values */
    for (i = T2_LOWER_BOUND ; i < T2_LOWER_BOUND + SRC_SIZE + DEST_SIZE ; ++i)
    {
	MU_ASSERT_EQUAL(t2[i], i - T2_LOWER_BOUND);
    }
}

MU_TEST(ajoute_apres, zero){
    int i;
    for (i = 0 ; i < T1_MAX_SIZE ; ++i)
	t1[i] = MAGIC;
    MU_ASSERT_EQUAL(ajoute_apres(t1,0,t2,0), t1);
    for (i = 0 ; i < T1_MAX_SIZE ; ++i)
	MU_ASSERT_EQUAL(t1[i], MAGIC);
}

MU_TEST(ajoute_apres, minus){
    int i;
    for (i = 0 ; i < T1_MAX_SIZE ; ++i)
    	t1[i] = MAGIC;
    MU_ASSERT_EQUAL(ajoute_apres(t1,-1,t2,-1), t1);
    for (i = 0 ; i < T1_MAX_SIZE ; ++i)
    	MU_ASSERT_EQUAL(t1[i], MAGIC);
}

MU_TEST_SUITE(ajoute_apres) = {
    MU_ADD_TEST(ajoute_apres, normal),
    MU_ADD_TEST(ajoute_apres, zero),
    MU_ADD_TEST(ajoute_apres, minus),
    MU_TEST_SUITE_END
};


/******************* Ex2 *************************/
MU_SETUP(rationnels){}
MU_TEAR_DOWN(rationnels){}
static int rat_equal(struct rat a, struct rat b)
{
    return a.num*b.den == a.den*b.num;
}

MU_TEST(rationnels, produit){
    struct rat a = {3,2};
    struct rat b = {5,3};
    struct rat res = {15,6};
    
    struct rat c = rat_produit(a,b);
    MU_ASSERT(rat_equal(c, res));
}


MU_TEST(rationnels, somme){
    struct rat a = {3,2};
    struct rat b = {5,3};
    struct rat res = {15,19};
    struct rat c = rat_somme(a,b);

    MU_ASSERT(rat_equal(c, res));
}

MU_TEST(rationnels, plus_petit){
    struct rat array[] = {
	{2,1},
	{8,9},
	{1,7},
	{1,1},
	{7,9},
	{5,8},
	{8,2}, /* smallest  one */
	{5,6},
	{7,5},
	{9,8},
	{0,0}
    };
    struct rat res = {8,2};
    
    struct rat a = rat_plus_petit(array);
    MU_ASSERT(rat_equal(a, res));
}

MU_TEST_SUITE(rationnels) = {
    MU_ADD_TEST(rationnels, produit),
    MU_ADD_TEST(rationnels, somme),
    MU_ADD_TEST(rationnels, plus_petit),
    MU_TEST_SUITE_END
};

int main(int argc, char **argv)
{
    MU_RUN_TEST_SUITE_WITH_REPORT(somme);
    MU_RUN_TEST_SUITE_WITH_REPORT(copie);
    MU_RUN_TEST_SUITE_WITH_REPORT(ajoute_apres);
    MU_RUN_TEST_SUITE_WITH_REPORT(rationnels);
    return 0;
}
