#include <iostream>
#include "../head.hpp"

int main()
{
    vector_Default_constructor();
    std::cin.ignore();

    vector_FillConstructor();
    std::cin.ignore();
    
    vector_FillConstructorSizedValue();
    std::cin.ignore();
    
    vector_RangeConstructor();
    std::cin.ignore();
    
    vector_CopyConstructor();
    std::cin.ignore();
    
    vectorAssignOperator();
    std::cin.ignore();
    
    vectorIteratorBegin();
    std::cin.ignore();
    
    vectorConstIteratorBegin();
    std::cin.ignore();
    
    vectorIteratorEnd();
    std::cin.ignore();
    
    vectorConstIteratorEnd();
    std::cin.ignore();
    
    vectorIteratorRbegin();
    std::cin.ignore();
    
    vectorConstIteratorRbegin();
    std::cin.ignore();
    
    vectorIteratorRend();
    std::cin.ignore();
    
    vectorConstIteratorRend();
    std::cin.ignore();
    
    vecotSizeMaximum();
    std::cin.ignore();
    
    vectorResize();
    std::cin.ignore();
    
    vectorEmtyTrue();
    std::cin.ignore();
    
    vectorEmtyFalse();
    std::cin.ignore();
    
    vectorOperator();
    std::cin.ignore();
    
    vectorConstOperator();
    std::cin.ignore();
    
    vectorAt();
    std::cin.ignore();
    
    vectorConstAt();
    std::cin.ignore();
    
    vectorFront();
    std::cin.ignore();
    
    vectorConstFront();
    std::cin.ignore();
    
    vectorBack();
    std::cin.ignore();
    
    vectorConstBack();
    std::cin.ignore();
    
    vectorAssignRange();
    std::cin.ignore();
    
    vectorPushBackEmpty();
    std::cin.ignore();
    
    vectorPushBack();
    std::cin.ignore();
    
    vectorPopBack();
    std::cin.ignore();
    
    vectorInsertSingleElement();
    std::cin.ignore();
    
    vectorInsertFill();
    std::cin.ignore();
    
    vectorEraseSingleElement();
    std::cin.ignore();
    
    vectorEraseRange();
    std::cin.ignore();
    
    vectorSwap();
    std::cin.ignore();
    
    vectorClear();
    std::cin.ignore();
    
    vectorRealationEqualTrue();
    std::cin.ignore();
    
    vectorRealationEqualFalse();
    std::cin.ignore();
    
    vectorRealationNotEqualTrue();
    std::cin.ignore();
    
    vectorRealationNotEqualFalse();
    std::cin.ignore();
    
    vectorSmallTrue();
    std::cin.ignore();
    
    vectorSmallFalse();
    std::cin.ignore();
    
    vectorMoreTrue();
    std::cin.ignore();
    
    vectorMoreFalse();

    std::cout << std::endl << "End!!!" << std::endl;
    return (0);
}