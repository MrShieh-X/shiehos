import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;

public class AsciiExecutor {
    public static void main(String[] args) throws IOException {
        getPicArrayData("D:\\AdministratorDocuments\\Virtual Machines\\Ubuntu21.04\\share\\edk2\\ShiehOS\\ascii_nobackground.png");
    }

    public static void getPicArrayData(String path) throws IOException {
        StringBuilder stringBuilder = new StringBuilder();
        BufferedImage bimg = ImageIO.read(new File(path));
        for (int y = 0; y < bimg.getHeight(); y++) {
        for (int x = 0; x < bimg.getWidth(); x++) {
                //输出一列数据比对
                String format = String.format("%x", bimg.getRGB(x, y));
                stringBuilder.append(format.length()==8?format.substring(0,2):"00");
            }
        }
        System.out.println(stringBuilder);
        hexWrite(stringBuilder.toString(), new File("ascii.hex"));
    }


    public static void hexWrite(String bytes, File file) throws IOException {
        hexWrite(hexString2Bytes(bytes), file);
    }

    public static void hexWrite(byte[] bytes, File file) throws IOException {
        file.createNewFile();
        FileOutputStream fop = new FileOutputStream(file);
        fop.write(bytes);
        fop.flush();
        fop.close();
    }

    public static boolean isEmpty(CharSequence c) {
        return c == null || c.length() == 0;
    }

    public static byte[] hexString2Bytes(String hex) {
        if (isEmpty(hex)) {
            return null;
        } else {
            int length = hex.length();
            if (length % 2 != 0) return null;
            byte[] bytes = new byte[length / 2];
            int j = 0;
            for (int i = 0; i < length; i += 2) {
                bytes[j++] = (byte) Integer.parseInt(hex.substring(i, i + 2), 16);
            }
            return bytes;
        }
    }
}