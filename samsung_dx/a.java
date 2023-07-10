import java.io.*;
import java.util.*;

public class a{
    public static StringBuilder sb;
    public static BufferedReader br;
    public static String result;
		public static int[][] graph;
		public static int[] row;
		public static int[] col;
		public static Set<Integer> rowSet;
		public static Set<Integer> colSet;


    public static void solve(int test) throws IOException {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			int q = Integer.parseInt(st.nextToken());

			graph = new int[n][m];
			row = new int[n];
			col = new int[m];

			rowSet = new HashSet<>();
			colSet = new HashSet<>();

			Arrays.fill(row, -1);
			Arrays.fill(col, -1);

			for(int i = 0; i < n; i++) {
				StringTokenizer gst = new StringTokenizer(br.readLine());
				for(int j = 0; j < m; j++) {
					int curr = Integer.parseInt(gst.nextToken());
					graph[i][j] = curr;
					row[i] = Math.max(row[i], curr);
					col[j] = Math.max(col[j], curr);
				}
			}

			int result = 0;
			int count = 0;

			for(int rowV: row) {
				rowSet.add(rowV);
			}

			for(int colV: col) {
				colSet.add(colV);
			}

			for(int value: row) {
				if(colSet.contains(value)) {
					count++;	
				}
			}
			//System.out.println("count " + count);
			//System.out.println(Arrays.toString(row));
			//System.out.println(Arrays.toString(col));

			for(int i = 0; i < q; i++) {
				StringTokenizer qst = new StringTokenizer(br.readLine());
				int r = Integer.parseInt(qst.nextToken()) - 1;
				int c = Integer.parseInt(qst.nextToken()) - 1;
				int x = Integer.parseInt(qst.nextToken());
				
				int prevRow = row[r];
				boolean f1 = colSet.contains(prevRow);
				int prevCol = col[c];
				boolean f2 = rowSet.contains(prevCol);
				rowSet.remove(prevRow);
				colSet.remove(prevCol);
				row[r] = Math.max(row[r], x);
				col[c] = Math.max(col[c], x);
				int tmp = 0;
				rowSet.add(row[r]);
				colSet.add(col[c]);

				if(prevCol == prevRow) {
					if(row[r] == col[c]) {
						tmp = 0;
					}	else {
						tmp = -1;
					}
				} else {
					int t1 = 0;
					int t2 = 0;
					if(f1) t1 += 1;
					if(f2) t2 += 1;

					if(prevRow != row[r]) {
						if(t1 == 1) tmp--; 
					}

					if(prevCol != col[c]) {
						if(t2 == 1) tmp--; 
					}

					if(row[r] == col[c]) tmp++;
				}
				count += tmp;
				//System.out.println("count " + count);
				//System.out.println(Arrays.toString(row));
				//System.out.println(Arrays.toString(col));
				result += count;
			}

			sb.append("#").append(test).append(" ").append(result).append("\n");
    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        sb = new StringBuilder();
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

				int t = Integer.parseInt(br.readLine());

				for(int i = 1; i < t + 1; i++) {
        	solve(i);
				}
        result = sb.toString();

        br.close();
        bw.write(result);
        bw.flush();
        bw.close();
    }
}

