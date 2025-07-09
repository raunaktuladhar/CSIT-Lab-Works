public class RunnableThreadDemo implements Runnable{
    public void run(){
        for(int i=1; i<=100; i++){

            // handling thread
            try{
                Thread.sleep(500);
            }

            catch(InterruptedException e){
                Thread.currentThread().interrupt();
                System.out.println("Error occured");
            }
        }
    }

    public static void main(String[] args) {
        Thread th1 = new Thread(new RunnableThreadDemo());
        th1.start();

        Thread th2 = new Thread(new RunnableThreadDemo());
        th2.start();  
    }
}
