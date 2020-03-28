import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.TreeMap;
import java.util.TreeSet;

public class F {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		TreeSet<String> words= new TreeSet<String>();
		int n = Integer.parseInt(br.readLine());
		for(int i = 0; i<n;i++) {
			String s = br.readLine().toLowerCase();
			s=s.replace('-', ' ');
			words.add(s);
		}
		bw.write(words.size()+"\n");
		bw.close();

	}

}
