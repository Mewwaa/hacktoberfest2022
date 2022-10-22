import java.io.*;
import java.util.*;

public class TSE {
	// there are four nodes in example graph (graph is
	// 1-based)

	static int n = 4;
	// give appropriate maximum to avoid overflow

	static int MAX = 1000000;

	// dist[i][j] represents shortest distance to go from i
	// to j this matrix can be calculated for any given
	// graph using all-pair shortest path algorithms
	static int[][] dist = {
		{ 0, 0, 0, 0, 0 }, { 0, 0, 10, 15, 20 },
		{ 0, 10, 0, 25, 25 }, { 0, 15, 25, 0, 30 },
		{ 0, 20, 25, 30, 0 },
	};

	// memoization for top down recursion

	static int[][] memo = new int[n + 1][1 << (n + 1)];

	static int fun(int i, int mask)
	{
		// base case
		// if only ith bit and 1st bit is set in our mask,
		// it implies we have visited all other nodes
		// already
		if (mask == ((1 << i) | 3))
			return dist[1][i];
		// memoization
		if (memo[i][mask] != 0)
			return memo[i][mask];

		int res = MAX; // result of this sub-problem

		// we have to travel all nodes j in mask and end the
		// path at ith node so for every node j in mask,
		// recursively calculate cost of travelling all
		// nodes in mask
		// except i and then travel back from node j to node
		// i taking the shortest path take the minimum of
		// all possible j nodes

		for (int j = 1; j <= n; j++)
			if ((mask & (1 << j)) != 0 && j != i && j != 1)
				res = Math.min(res,
							fun(j, mask & (~(1 << i)))
								+ dist[j][i]);
		return memo[i][mask] = res;
	}

	// Driver program to test above logic
	public static void main(String[] args)
	{
		int ans = MAX;
		for (int i = 1; i <= n; i++)
			// try to go from node 1 visiting all nodes in
			// between to i then return from i taking the
			// shortest route to 1
			ans = Math.min(ans, fun(i, (1 << (n + 1)) - 1)
									+ dist[i][1]);

		System.out.println(
			"The cost of most efficient tour = " + ans);
	}
}
