#include <assert.h>
#include "queue.h"

int main()
{
    int result1;
    int result2;
    char testChar;
    
    // *******************************************************************
    // Test1: Retrieve item from an empty queue
    // *******************************************************************
    // Arrange:
    result1 = 42;
    testChar = 'Z';
    queue_init();
    
    // Act:
    result1 = queue_get(&testChar);
      
    // Assert:
    assert(-1 == result1);
    assert('Z' == testChar);
    
    
    // *******************************************************************
    // Test2: Successfully retrieve an item from the queue
    // *******************************************************************
    // Arrange:
    result1 = 42;
    result2 = 42;
    testChar = 'Z';
    queue_init();
    
    // Act:
    result1 = queue_put('A');
    result2 = queue_get(&testChar);
    
    // Assert:
    assert(0 == result1);
    assert(0 == result2);
    assert('A' == testChar);
    
    
    // *******************************************************************
    // Test3: Fill queue, then get all items.
    // *******************************************************************
    // Arrange:
    testChar = 'Z';
    queue_init();
    
    // Act:
    queue_put('A');
    queue_put('B');
    queue_put('C');                                    
    
    // Assert:
    assert(0 == queue_get(&testChar));
    assert('A' == testChar);

    assert(0 == queue_get(&testChar));
    assert('B' == testChar);

    assert(0 == queue_get(&testChar));
    assert('C' == testChar);

    
    // *******************************************************************
    // Test4: Fill queue, then put one more item, should fail
    // *******************************************************************
    // Arrange:
    testChar = 'Z';
    queue_init();
    
    // Act:
    queue_put('A');
    queue_put('B');
    queue_put('C');
    
    // Assert:
    assert(-1 == queue_put('D'));

    assert(0 == queue_get(&testChar));
    assert('A' == testChar);

    assert(0 == queue_get(&testChar));
    assert('B' == testChar);

    assert(0 == queue_get(&testChar));
    assert('C' == testChar);



    // ***********************************************************************
    // Test5: Fill queue, retrieve one item, then add item, then retieve all
    // ***********************************************************************
    // Arrange:
    testChar = 'Z';
    queue_init();
    
    // Act:
    queue_put('A');
    queue_put('B');
    queue_put('C');
    
    // Assert:
    assert(0 == queue_get(&testChar));
    assert('A' == testChar);

    assert(0 == queue_put('D'));

    assert(0 == queue_get(&testChar));
    assert('B' == testChar);

    assert(0 == queue_get(&testChar));
    assert('C' == testChar);

    assert(0 == queue_get(&testChar));
    assert('D' == testChar);

    // ***********************************************************************
    // Test6: Fill queue and retrieve all items twice
    // ***********************************************************************
    // Arrange:
    testChar = 'Z';
    queue_init();
    
    // Act:
    queue_put('A');
    queue_put('B');
    queue_put('C');
    
    // Assert:
    assert(0 == queue_get(&testChar));
    assert('A' == testChar);

    assert(0 == queue_get(&testChar));
    assert('B' == testChar);

    assert(0 == queue_get(&testChar));
    assert('C' == testChar);

    assert(0 == queue_put('D'));
    assert(0 == queue_put('E'));
    assert(0 == queue_put('F'));
    
    assert(-1 == queue_put('Z'));

    assert(0 == queue_get(&testChar));
    assert('D' == testChar);
   
    assert(0 == queue_get(&testChar));
    assert('E' == testChar);

    assert(0 == queue_get(&testChar));
    assert('F' == testChar);

    return 0;
}
