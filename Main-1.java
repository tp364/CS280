// Main.java
import java.io.*;

public class Main {
    private static String s;
    private static int i;

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new FileReader("input.txt"))) {
            String line;
            while ((line = br.readLine()) != null) {
                s = line;
                i = 0;
                if (S() && i == s.length()) {
                    System.out.println("The string \"" + line + "\" is in the language.");
                } else {
                    System.out.println("The string \"" + line + "\" is not in the language.");
                }
            }
        } catch (FileNotFoundException e) {
            System.out.println("Error: input.txt not found. Please make sure the file exists in the program directory.");
        } catch (IOException e) {
            System.out.println("Error reading from input.txt: " + e.getMessage());
        }
    }


    private static boolean S() {
        int savedI = i;
        if (I()) {
            if (i < s.length() && s.charAt(i) == '=') {
                ++i;
                if (E()) {
                    return true;
                }
            }
        }
        i = savedI;
        return false;
    }

    private static boolean E() {
        if (T()) {
            if (i < s.length() && (s.charAt(i) == '+' || s.charAt(i) == '-')) {
                ++i;
                return E();
            }
            return true;
        }
        return false;
    }

    private static boolean T() {
        if (F()) {
            if (i < s.length() && (s.charAt(i) == '*' || s.charAt(i) == '/')) {
                ++i;
                return T();
            }
            return true;
        }
        return false;
    }

    private static boolean F() {
        if (I() || D()) {
            return true;
        } else if (i < s.length() && s.charAt(i) == '(') {
            ++i;
            if (E() && i < s.length() && s.charAt(i) == ')') {
                ++i;
                return true;
            }
        }
        return false;
    }

    private static boolean I() {
        if (i < s.length() && Character.isLowerCase(s.charAt(i))) {
            ++i;
            while (i < s.length() && Character.isLowerCase(s.charAt(i))) {
                ++i;
            }
            return true;
        }
        return false;
    }


    private static boolean D() {
        int start = i;
        while (i < s.length() && Character.isDigit(s.charAt(i))) {
            ++i;
        }
        return i > start;
    }
}
