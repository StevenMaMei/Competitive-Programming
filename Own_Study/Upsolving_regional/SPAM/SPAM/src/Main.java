import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;

class Main {
	
	static long[] memo;
	static long mod = (long)Math.pow(10, 9)+7;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		String[] nl = br.readLine().split(" ");
		int n = Integer.parseInt(nl[0]);
		int l = Integer.parseInt(nl[1]);
		node[] nodos = new node[n+1];
		memo = new long[n+1];
		for(int i =1; i <= l; i++) {
			String[] info = br.readLine().split(" ");
			nodos[i]= new node();
			for(int j = 1; j < info.length; j++) {
				memo[i]=-1;
				nodos[i].vecinos.add(Integer.parseInt(info[j]));
			}
		}
		
		
		for(int i = l+1; i<= n; i++) {
			memo[i]= -1;
			nodos[i]= new node();
		}
		long r1= dfs(nodos,1);
		long r2=0;
		for(int i = l+1; i <= n;i++) {
			if(memo[i]!= -1) {
				r2++;
				r2%= mod;
				
			}
		}
		bw.write(r1+"\n");
		bw.write(r2+"\n");
		bw.close();
	}
	
	public static long dfs(node[] nodos, int no) {
		node nodo= nodos[no];
		if(nodo.vecinos.size()== 0) {
			memo[no]=1;
			return 1;
		}
		if(memo[no] != -1) {
			System.out.println("wntro");
			return memo[no];
		}
		long cant = 0;
		ArrayList<Integer> vecinos= nodo.vecinos;
		for(int i =0 ; i< vecinos.size();i++) {
			if(memo[vecinos.get(i)]!= -1) {
				
				cant+= memo[vecinos.get(i)]%mod;
			}else {
				cant+= dfs(nodos, vecinos.get(i))%mod;				
			}
			cant%= mod;
		}
		return memo[no]=cant; 
	}
	

}

class node{
	
	ArrayList<Integer> vecinos = new ArrayList<Integer>();
}
