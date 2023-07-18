import java.io.*;
import java.util.*;

public class b{
    public static StringBuilder sb;
    public static BufferedReader br;
    public static String result;
		public static int[][] graph;

    public static void solve(int test) throws IOException {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			int MAX = Integer.MAX_VALUE;
			graph = new int[n+1][n+1];

			for(int i = 0; i <= n; i++) {
				Arrays.fill(graph[i], 1000000000);
			}

			for(int i = 0; i < m; i++) {
				StringTokenizer mst = new StringTokenizer(br.readLine());
				int x = Integer.parseInt(mst.nextToken());
				int y = Integer.parseInt(mst.nextToken());
				int c = Integer.parseInt(mst.nextToken());

				if(x == y) {
					MAX = Math.min(MAX, c);
					continue;
				}

				graph[x][y] = c;
			}

			for(int i = 1; i <= n; i++) {
				for(int j = 1; j <= n; j++)	{
					if(i == j) {
						graph[i][j] = 0;	
					}	
				}
			}

			for(int k = 1; k <= n; k++) {
				for(int i = 1; i <= n; i++)	 {
					for(int j = 1; j <= n; j++) {
						graph[i][j] = Math.min(graph[i][j], graph[i][k] + graph[k][j]);
					}	
				}
			}

			for(int i = 1; i <= n; i++) {
				for(int j = 1; j <= n; j++) {
					if(i == j) continue;	

					if(graph[i][j] != 1000000000 && graph[j][i] != 1000000000) {
						MAX = Math.min(MAX, graph[i][j] + graph[j][i]);
					}
				}	
			}
			//System.out.println(Arrays.deepToString(graph));
			
			if(MAX == Integer.MAX_VALUE) {
				MAX = -1;	
			}

			sb.append("#").append(test).append(" ").append(MAX).append("\n");
    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        sb = new StringBuilder();
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

				int t = Integer.parseInt(br.readLine().strip());

				for(int i = 1; i <= t; i++) {
        	solve(i);
				}
        result = sb.toString();

        br.close();
        bw.write(result);
        bw.flush();
        bw.close();
    }
}

