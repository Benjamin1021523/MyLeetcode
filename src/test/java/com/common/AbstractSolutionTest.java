package com.common;

import java.util.Map;

public abstract class AbstractSolutionTest<M, N> {
    protected Map<M, N> checkPoints;

    protected static int[] toIntArray(Integer[] integerArray) {
        int[] intArray = new int[integerArray.length];
        for (int i = 0; i < integerArray.length; i++) {
            if(integerArray[i] != null){
                intArray[i] = integerArray[i];
            }
        }
        return intArray;
    }
}
