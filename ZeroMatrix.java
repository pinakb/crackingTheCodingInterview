package com.java.code.roop;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class ZeroMatrix {

	public static void main(String[] args) {

		int m[][] = { { 1, 2, 0, 4 }, { 5, 6, 7, 8 }, { 9, 0, 11, 12 }};
		printArr(m);
		
		int rowL = m.length;
		int colL = m[0].length;
		for (int i = 0; i < rowL; i++) {
			for (int j = 0; j < colL; j++) {
				if (m[i][j] == 0) {
					for (int k = 0; k < rowL; k++)
						if (m[k][j] != 0)
							m[k][j] = -1;

					for (int l = 0; l < colL; l++)
						if (m[i][l] != 0)
							m[i][l] = -1;
				}
			}
		}
		
		for (int i=0;i<m.length;i++) {
			for (int j=0;j<m[i].length;j++) {
				if (m[i][j]== -1)
					m[i][j] = 0;
			}
		}
		
/*		int counter = 1;
 		List<Integer> indexList = null;
		Map<Integer, List<Integer>> mMap = new HashMap<Integer, List<Integer>>();
		for (int i = 0; i < m.length; i++) {
			for (int j = 0; j < m[i].length; j++) {
				if (m[i][j]==0) {
					indexList = new ArrayList<Integer>();
					indexList.add(i);
					indexList.add(j);
					mMap.put(counter, indexList);
					counter++;
				}
			}
		}
		
        for (Integer key : mMap.keySet()) {
            List<Integer> valueList = mMap.get(key);
            for (int i = 0; i<m.length;i++) {
            	m[i][valueList.get(1)] = 0;
            	for (int j =0;j<m[i].length;j++) {
            		m[valueList.get(0)][j]= 0;
            	}
            }
            System.out.println();
        }
*/
        System.out.println();
        printArr(m);
	}

	private static void printArr(int m[][]) {
		for (int i = 0; i < m.length; i++) {
			System.out.print("\n");
			for (int j = 0; j < m[i].length; j++)
				System.out.print(m[i][j] + " ");
		}
	}
}
