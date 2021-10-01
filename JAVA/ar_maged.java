import java.security.*;
import java.security.interfaces.DSAPrivateKey;
import java.security.interfaces.DSAPublicKey;

public class DSA {
  public static KeyPair buildKeyPair() throws NoSuchAlgorithmException {
    KeyPairGenerator keyGenerator = KeyPairGenerator.getInstance("DSA");
    keyGenerator.initialize(1024);
    return keyGenerator.genKeyPair();
  }

  public static byte[] sign(DSAPrivateKey privateKey, byte[] message)
      throws NoSuchAlgorithmException, InvalidKeyException, SignatureException {
    Signature signAlgorithm = Signature.getInstance("DSA");
    
    signAlgorithm.initSign(privateKey);
    signAlgorithm.update(message);
    
    return signAlgorithm.sign();
  }

  public static boolean verify(DSAPublicKey publicKey, byte[] message, byte[] signature)
      throws NoSuchAlgorithmException, InvalidKeyException, SignatureException {
    Signature verifyAlgorithm = Signature.getInstance("DSA");
    
    verifyAlgorithm.initVerify(publicKey);
    verifyAlgorithm.update(message);
    
    return verifyAlgorithm.verify(signature);
  }
}