import java.util.Scanner;

public class MuhammadFaruqi_2308107010005_Soal3 {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);

        System.out.print("Masukkan sebuah kalimat: ");
        String kalimat = in.nextLine();

        System.out.print("Masukkan indeks awal: ");
        int indeksAwal = in.nextInt();

        System.out.print("Masukkan indeks akhir: ");
        int indeksAkhir = in.nextInt();

        if(indeksAwal >= 0 && indeksAkhir <= kalimat.length() && indeksAwal < indeksAkhir){
            String substring = kalimat.substring(indeksAwal, indeksAkhir);
            System.out.println("------------------------------------");
            System.out.println("\t Substring Finder");
            System.out.println("------------------------------------");
            System.out.println("Teks asli: " + kalimat);
            System.out.println("Substring dari indeks " + indeksAwal + " hingga indeks " + indeksAkhir + " adalah: " + substring);
            System.out.println("------------------------------------");

        }
        else{
            System.out.println("Input tidak valid");
        }

        in.close();
    }
}
