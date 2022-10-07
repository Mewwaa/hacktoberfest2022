package com.programs;
import java.util.*;

public class LargestSubarrayWith0Sum {

	public static void main(String[] args) {
		int arr[] = {15,-2,2,-8,1,7,10,23};
		HashMap<Integer,Integer> map = new HashMap<>();
		int sum=0;
		int len =0;
		
		for(int j=0;j<arr.length;j++) {
			sum+=arr[j];
			if(map.containsKey(sum)) {
				len = Math.max(len, j-map.get(sum));
			}
			else {
				map.put(sum, j);
			}
		}
		System.out.println("the largest subarray with sum as 0"+len);
		
	}

}
