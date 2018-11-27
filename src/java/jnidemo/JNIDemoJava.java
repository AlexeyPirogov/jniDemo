package jnidemo;


public class JNIDemoJava {

    static {
        System.load("/home/alex/src/JNIExperiments/JNIDemo/dist/libJNIDemo.so");
    }
    
    private static final int REPETITIONS = 100_000_000;

    private native int nativeCrash();
    private native int nativePrint();
    private native int nativeSleep(int ms);
    private native Double[] nativeAllocate(int n);

    public static void main(String[] args) {
        JNIDemoJava nativeCall = new JNIDemoJava();

        for (int i = 0; i < REPETITIONS; i++) {
            nativeCall.nativePrint();
            nativeCall.nativeSleep(1000);
            Double[] dArr = nativeCall.nativeAllocate(100);
            for (Double d : dArr) {
                System.out.println(System.currentTimeMillis());
            }
        }
    }
}