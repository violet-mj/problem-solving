import java.io.*;
import java.util.*;

public class p11048{
    public static StringBuilder sb;
    public static BufferedReader br;
    public static String result;

    public static void solve() throws IOException {
			StringTokenizer st = new StringTokenizer(br.readLine());

			List<List<Integer>> graph = new ArrayList();

			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			int[][] dp = new int[n+1][m+1];
			graph.add(new ArrayList<Integer>());

			for(int i = 0; i < m; i++) {
				graph.get(0).add(0);
			}

			for(int i = 0; i < n; i++) {
				graph.add(new ArrayList<Integer>());
				StringTokenizer lst = new StringTokenizer(br.readLine());
				graph.get(i+1).add(0);		
				while(lst.hasMoreTokens()) {
					graph.get(i + 1).add(Integer.parseInt(lst.nextToken()));
				}
			}

			for(int i = 1; i < n + 1; i++) {
				for(int j = 1; j < m + 1; j++) {
					int max_ = -1;	
					if(dp[i-1][j] + graph.get(i).get(j) > max_) {
						max_ = Math.max(max_, dp[i-1][j] + graph.get(i).get(j));
					}

					if(dp[i-1][j-1] + graph.get(i).get(j) > max_) {
						max_ = Math.max(max_, dp[i-1][j-1] + graph.get(i).get(j));
					}

					if(dp[i][j-1] + graph.get(i).get(j) > max_) {
						max_ = Math.max(max_, dp[i][j-1] + graph.get(i).get(j));
					}

					dp[i][j] = max_;
				}	
			}

			sb.append(dp[n][m]).append("\n");

    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        sb = new StringBuilder();
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        solve();
        result = sb.toString();

        br.close();
        bw.write(result);
        bw.flush();
        bw.close();
    }
}

