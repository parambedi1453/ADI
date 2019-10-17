import java.util.*;
import param_ds.*;
class Playlist
{
    private static class Song
    {
        private int songname;
        // private Song next;
        // private Song prev;

        // public Song(int sname,Song n,Song p)
        // {
        //
        // }
        public Song(int s)
        { songname = s;}
    }
    private char playlistName;
    private int playlistMode;
    private DoublyLinkedList<Song> dob;

    // public void printPlaylist(DoublyLinkedList<Song> obj)
    // {
    //     System.out.println(objsongname);
    // }
    public Playlist(char pname)
    {
        playlistName = pname;
        dob = new DoublyLinkedList<Song>();
    }
    public void addSong(int name)
    {
        Song sob = new Song(name);
        dob.addLast(sob);
    }
    public void getSongList()
    {
        System.out.println(dob.songname);
    }
    public void getFirstSong()
    {
        Song k = dob.first();
        System.out.println(k.songname);
    }
    public void getSize()
    {
        System.out.println(dob.size());
    }
}
public class Mainmenu
{
    public static void main(String args[])
    {
        System.out.println("\n");
        System.out.println("\t\t\t********Main Menu**********\t\t\t\t");
        System.out.println("\t\t\t Press 1 to create playlist");
        System.out.println("\t\t\t Press 2 to exit \n\n");
         Scanner sc = new Scanner(System.in);
        int menuOption = sc.nextInt();
        System.out.println("Enter Playlist Name = ");
        char pname = sc.next().charAt(0);
        Playlist pob = new Playlist(pname);
        System.out.println("\t\t\t**********Playlist Created************\t\t\t");
        System.out.println("\t\t\t Playlist Name ="+pname);
        System.out.println("\n ************** PLAYLIST OPTIONS****************");
        System.out.println("press 1 to add song");
        System.out.println("press 2 to display list");
        System.out.println("press 3 to ") ;
        System.out.println("press 4 to ");
        System.out.println("press 5 to  ");

        pob.getSize();
        pob.addSong(1);
        pob.addSong(2);
        pob.addSong(3);
        pob.getSongList();
        pob.getFirstSong();
        pob.getSize();
    }
}
