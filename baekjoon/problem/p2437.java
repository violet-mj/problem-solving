
import java.io.*;
import java.util.*;

public class p2437{
    public static StringBuilder sb;
    public static BufferedReader br;
    public static String result;
    public static List<Integer> weights;

    public static void solve() throws IOException {
        int n = Integer.parseInt(br.readLine());
        weights = new ArrayList<>();
        StringTokenizer lst = new StringTokenizer(br.readLine());

        while(lst.hasMoreTokens()) {
            weights.add(Integer.parseInt(lst.nextToken()));
        }
        
        Collections.sort(weights);

        int result = 0;

        for(int weight: weights) {
						// System.out.println("weight : " + weight + " result : " + result);
            if(result + 1 >= weight) {
                result += weight;
            } else {
                break;
            }
        }

        sb.append(result + 1).append("\n");
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

