package project_tools;

import java.io.File;
import java.io.FileOutputStream;

public class SignWriter {
    /**
     * Format: <Unlimited: hexadecimal time> <One digit: number of digits in hexadecimal time> 00 00 00 53 68 69 65 68 4F 53 <Three digits: version of the operating system>
     */
    public static void main(String[] args) throws Throwable {
        File kernel = new File(args[0]);

        String versionCode = new String(Long.toString(Long.parseLong(args[1]), 16));

        int o = versionCode.length();
        for (int i = 0; i < (6 - o); i++) {
            versionCode = "0" + versionCode;
        }
        byte[] versionCodeBytes = hexString2Bytes(versionCode.toString());

        String time = Long.toString(System.currentTimeMillis() / 1000, 16);
        if (time.length() % 2 != 0) {
            time = "0" + time;
        }
        int timeLength = time.length() / 2;
        byte[] timeBytes = hexString2Bytes(time);
        byte[] second = new byte[]{(byte) timeLength, (byte) 0x00, (byte) 0x00, (byte) 0x00, (byte) 0x53, (byte) 0x68, (byte) 0x69, (byte) 0x65, (byte) 0x68, (byte) 0x4F, (byte) 0x53, versionCodeBytes[0], versionCodeBytes[1], versionCodeBytes[2]};
        System.out.println(new String(timeBytes) + new String(second));
        System.out.println(bytesToString(timeBytes) + bytesToString(second));
        FileOutputStream fileOutputStream = new FileOutputStream(kernel, true);
        fileOutputStream.write(timeBytes);
        fileOutputStream.write(second);
        fileOutputStream.flush();
        fileOutputStream.close();
    }

    public static boolean isEmpty(CharSequence s) {
        return s == null || s.length() == 0;
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

    public static String bytesToString(byte[] bytes) {
        StringBuilder builder = new StringBuilder();
        for (byte aByte : bytes) {
            builder.append(String.format("%02X", aByte)).append(' ');
        }
        return builder.toString().toUpperCase();
    }
}
