
import java.io.*;
import java.util.*;

public class d{
    public static StringBuilder sb;
    public static BufferedReader br;
    public static String result;
		public static int n;
		public static List<Integer> leafs;
		public static List<List<Integer>> graph;

		public static int dfs(int node, int prevNode)  {
			if(!leafs.get(node).equals(-1)) {
				return leafs.get(node);
			}

			if(graph.get(node).size() == 1 && node != 1) {
				leafs.set(node, 1);
				return leafs.get(node);
			}

			int l = 0;

			for(int nextNode: graph.get(node)) {
				if(nextNode != prevNode) {
					l += dfs(nextNode, node);
				}
			}

			leafs.set(node, l);
			return leafs.get(node);
		}

    public static void solve() throws IOException {
			n = Integer.parseInt(br.readLine());
			graph = new ArrayList<>();

			for(int i = 0; i < n + 1; i++ ) {
				graph.add(new ArrayList<Integer>());
			}

			for(int i = 0; i < n - 1; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());

				graph.get(a).add(b);
				graph.get(b).add(a);
			}

			leafs = new ArrayList();

			for(int i = 0; i < n + 1; i++) {
				leafs.add(-1);
			}

			dfs(1, -1);

			int q = Integer.parseInt(br.readLine());

			for(int i = 0; i < q; i++) {
				StringTokenizer qst = new StringTokenizer(br.readLine());
				int qa = Integer.parseInt(qst.nextToken());
				int qb = Integer.parseInt(qst.nextToken());

				sb.append((long)leafs.get(qa) * leafs.get(qb)).append("\n");
			}

    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        sb = new StringBuilder();
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
				int t = Integer.parseInt(br.readLine());

				for(int i = 0; i < t; i++) {
					solve();
				}
        result = sb.toString();

        br.close();
        bw.write(result);
        bw.flush();
        bw.close();
    }
}

