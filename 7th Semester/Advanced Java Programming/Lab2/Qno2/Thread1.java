public class Thread1 extends Thread{
    public void run(){
        for(int i=1; i<=100; i++){
            System.out.println(this.getName() + " : " + i); // this.getName() java ko built-in class Thread bata aayeh ko ho

            // handling thread
            try{
                Thread.sleep(500);
            }

            catch(Exception e){
                Thread.currentThread().interrupt();
                System.out.println("Error occured");
            }
        }
    }

    public static void main(String[] args) {
        Thread1 t1 = new Thread1();
        t1.setName("Thread no. 1");

        Thread1 t2 = new Thread1();
        t2.setName("Thread no. 2");

        t1.start();
        t2.start();
    }
}
