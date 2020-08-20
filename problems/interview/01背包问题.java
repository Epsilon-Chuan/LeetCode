/*
0-1背包问题：每个物品无非是装入背包或者不装入背包，即每个物品的取值无非就是0或者1，故这类题被称为0-1背包问题。

有 N 件物品和一个最大承重是 M 的背包。每件物品只能使用一次。

第 i 件物品的重量是 wi，价值是 vi。

求解将哪些物品装入背包，可使这些物品的总重量不超过背包最大承重 M
，且总价值最大。 输出最大价值。

输入格式
----------
第一行两个整数，N，M，用空格隔开，分别表示物品数量和背包最大承重。
接下来有 N 行，每行两个整数 wi,vi，用空格隔开，分别表示第 i 件物品的重量和价值。

输出格式
----------
输出一个整数，表示最大价值。

数据范围
----------
0 < N, M ≤ 1000, 0 < wi, vi ≤ 1000

输入样例
4 5
1 2
2 4
3 4
4 5

输出样例：
8
*/

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt(), M = in.nextInt();
        int[] w = new int[N + 1], v = new int[N + 1]; // 重量和价值
        for (int i = 1; i <= N; ++i) {
            w[i] = in.nextInt();
            v[i] = in.nextInt();
        }
        // dp[i][j]: 如果可选物品为（前） i 个物品、背包总可承重为 j，最大的价值
        int[][] dp = new int[N + 1][M + 1];
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= M; ++j)
                if (j < w[i]) // 背包承受力 < 当前物品重量，价值不变
                    dp[i][j] = dp[i - 1][j];
                else // 当前物品重量在承受范围内，但需判断“装 or 不装”
                    dp[i][j] = Math.max(dp[i - 1][j - w[i]] + v[i], dp[i - 1][j]);
        System.out.println(dp[N][M]);
    }
}
