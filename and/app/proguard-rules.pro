# If you keep the line number information, uncomment this to
# hide the original source file name.
-renamesourcefileattribute SourceFile

 # Keep generic signature of Call, Response (R8 full mode strips signatures from non-kept items).
 -keep,allowobfuscation,allowshrinking interface retrofit2.Call
 -keep,allowobfuscation,allowshrinking class retrofit2.Response

 # With R8 full mode generic signatures are stripped for classes that are not
 # kept. Suspend functions are wrapped in continuations where the type argument
 # is used.
 -keep,allowobfuscation,allowshrinking class kotlin.coroutines.Continuation
-keep class ro.kofe.** { *; }
-keep class okhttp3.** { *; }

 -if class * {
   @com.google.gson.annotations.SerializedName <fields>;
 }

 -keep class <1> {
   <init>();
 }

 ## Retrofit
 # Retain generic type information for use by reflection by converters and adapters.
 -keepattributes Signature
 # Retain service method parameters.
 -keepclassmembers,allowobfuscation interface * {
     @retrofit2.http.* <methods>;
 }
 # Ignore annotation used for build tooling.
 -dontwarn org.codehaus.mojo.animal_sniffer.IgnoreJRERequirement

 ## OkHttp3
 -dontwarn okhttp3.**
 -dontwarn okio.**
 -dontwarn javax.annotation.**
 -dontwarn org.conscrypt.**
 # A resource is loaded with a relative path so the package of this class must be preserved.
 -keepnames class okhttp3.internal.publicsuffix.PublicSuffixDatabase

 ## Kotlinx serialization
 -keepattributes *Annotation*, InnerClasses
 -dontnote kotlinx.serialization.SerializationKt
 -keep,includedescriptorclasses class ro.kofe.**$$serializer { *; } # <-- change package name to your app's
 -keepclassmembers class ro.kofe.** { # <-- change package name to your app's
     *** Companion;
 }
 -keepclasseswithmembers class ro.kofe.** { # <-- change package name to your app's
     kotlinx.serialization.KSerializer serializer(...);
 }

