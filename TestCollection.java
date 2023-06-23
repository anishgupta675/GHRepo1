import java.util.*;

public class TestCollection {
    public static void main(String[] args) throws Exception {
        Object al = new ArrayList();
        Object hs = new HashSet();
        Object hm = new HashMap();
        System.out.printf("%s %s %s", al instanceof Collection, hs instanceof Collection, hm instanceof Collection);
    }
}