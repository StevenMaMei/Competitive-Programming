import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.TreeMap;
import java.util.TreeSet;



 class E {

	public static void main(String[] args) throws IOException {
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		String cake = br.readLine();
		int s= Integer.parseInt(br.readLine())-1;
		int len = cake.length();
		TreeSet<Integer> pos= new TreeSet<Integer>();
		cake += cake;
		int cante= 0;
		for(int i =0; i<cake.length();i++) {
			if(cake.charAt(i)== 'E') {
				pos.add(i);
				if(i<len) {
					cante++;
				}
			}
			
		}
		long cant =0;
		
		for(int i =0; i< len; i++) {
			int prox =0;
			try {
				prox = pos.ceiling(i);
				
			}catch(Exception e) {
				
				break;
			}
			if(prox<s+i) {
//				System.out.println(s-(prox-i));
				cant+= i+s-prox+1;
				
			}else if(prox == s+i) {
//				System.out.println(1);
				cant+= 1;
			}
		}
//		cant+= cante;
		bw.write(cant+"\n");
		bw.close();
	}

}
