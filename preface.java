/*
ID: manubha1
LANG: JAVA
TASK: preface
*/
import java.io.*;
import java.util.*;

class preface {
  int N;
  public static void main (String [] args) throws IOException {
    // Use BufferedReader rather than RandomAccessFile; it's much faster
    preface obj = new Object
    BufferedReader f = new BufferedReader(new FileReader("preface.in"));
                                                  // input file name goes above
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("preface.out")));
    // Use StringTokenizer vs. readLine/split -- lots faster
    StringTokenizer st = new StringTokenizer(f.readLine());
						  // Get line, break into tokens
    int i1 = Integer.parseInt(st.nextToken());    // first integer
    
    out.close();                                  // close the output file
    System.exit(0);                               // don't omit this!
  }
}