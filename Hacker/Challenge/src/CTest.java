import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.Locale;
import java.util.Scanner;

public class CTest {

    public void deligant() {
        int res = 0;
        for (int i = 0; i <= 2118; ++i) {
            res += i;
        }
        for (int i = 1; i <= (int) Math.sqrt(2118); ++i) {
            res += i * i;
        }
        System.out.println(res);
    }

    public void most9Letters(String filename) {
        Scanner s = null;
        try {
            File file = new File(filename);
            FileInputStream fis = new FileInputStream(file);
            String CHARSET_NAME = "utf-8";
            Locale LOCALE = Locale.US;
            s = new Scanner(new BufferedInputStream(fis), CHARSET_NAME);
            s.useLocale(LOCALE);
        } catch (FileNotFoundException ex) {
            System.out.println("File can not be found.");
        }
        if (null != s) {
            HashMap<String, Integer> cnt = new HashMap<>();
            while (s.hasNextLine()) {
                String[] words = s.nextLine().split(" ");
                for (int i = 0; i < words.length; ++i) {
                    if (9 == words[i].length()) {
                        Integer cur = cnt.get(words[i]);
                        if (null != cur) {
                            ++cur;
                            cnt.put(words[i], cur);
                        } else {
                            cnt.put(words[i], 1);
                        }
                    }
                }
            }
            int most = -1;
            String word = "";
            for (String str : cnt.keySet()) {
                if (most < cnt.get(str)) {
                    most = cnt.get(str);
                    word = str;
                }
            }
            System.out.println(word + " : " + most);
        }

    }

    private long calc(int depth) {
        if (depth == 0) return 1;
        long cc = calc(depth - 1);
        return cc + (depth % 7) + ((((cc ^ depth) % 4) == 0) ? 1 : 0);
    }

    public static void main(String args[]) {
        CTest ct = new CTest();
        int res = 1;
        for (int i = 2; i < 20; ++i) {
            res *= i;
            System.out.println(i + " : " + res);
        }
    }
}
