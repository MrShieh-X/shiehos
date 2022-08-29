import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;

public class AsciiExecutor {
    public static void main(String[] args) throws IOException {
        getPicArrayData("D:\\AdministratorDocuments\\Virtual Machines\\Ubuntu21.04\\share\\edk2\\ShiehOS\\resources\\ascii\\ascii_nobackground.png");
    }

    public static void getPicArrayData(String path) throws IOException {
        StringBuilder stringBuilder = new StringBuilder();
        BufferedImage bimg = ImageIO.read(new File(path));
        for (int y = 0; y < bimg.getHeight(); y++) {
            for (int x = 0; x < bimg.getWidth(); x++) {
                int rgbInt = bimg.getRGB(x, y);
                String format = String.format("%x", rgbInt);
                String alpha = format.length() == 8 ? format.substring(0, 2) : "00";
                if (y >= 75 && y <= 104 && x >= 621 && x <= 638) {
                    //if(format.length()==8){
                    //It must be eight digit (with transparency)

                    if ("ffffff".equals(format.substring(2))) {
                        stringBuilder.append(alpha);
                    } else if ("000000".equals(format.substring(2))) {
                        stringBuilder.append("00");
                    } else {
                        String s = calculateAlphaOfLastChar(format.substring(2));
                        stringBuilder.append(s);
                        //System.out.println(s);
                    }

                    //}

                } else {
                    stringBuilder.append(alpha);
                }
            }
        }
        System.out.println(stringBuilder);
        hexWrite(stringBuilder.toString(), new File("ascii.hex"));
    }

    public static String calculateAlphaOfLastChar(String sixDigitColor) {
        int color = Integer.parseInt(sixDigitColor, 16);
        //(colorRed-0xff)/0xff
        String s = Integer.toString(0xff - (int) (((double) 0xffffff - (double) color) / (double) 0xffffff * 255.0), 16);
        return s.length() == 1 ? "0" + s : s;
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