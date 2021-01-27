import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
import java.security.*;
import java.util.regex.*;
import java.util.concurrent.*;
class OrderedStream {
    String[] string;
    int ptr;
    public OrderedStream(int n) {
        string = new String[n + 1];
        ptr = 1;
    }
    public List<String> insert(int id, String value) {
        List<String> list = new ArrayList<>();
        string[id] = value;
        if(id == ptr) {
            while(ptr < string.length && string[ptr] != null)
                list.add(string[ptr++]);
        }
        return list;
    }
    // Driver Code
    public static void main(String[] args) throws IOException {
	DataInputStream in = new DataInputStream(System.in);
	int n = Integer.parseInt(in.readLine()); List<String> list = new ArrayList<>(n);
	OrderedStream os = new OrderedStream(n);
	for(int i = 0; i < n; i++) {
		int id = Integer.parseInt(in.readLine());
		String value = in.readLine();
		list = os.insert((id - 1), value);
	}
	for(int i = 0; i < n; i++)
		System.out.print(list.get(i) + " ");
    }
}
/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream obj = new OrderedStream(n);
 * List<String> param_1 = obj.insert(id,value);
 */