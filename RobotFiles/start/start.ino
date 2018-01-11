
String xxx = "hello1";
void setup(){
int StringContains(String s, String search) {
    int max = s.length() - search.length();
    int lgsearch = search.length();

    for (int i = 0; i <= max; i++) {
        if (s.substring(i, i + lgsearch) == search) return i;
    }

 return -1;
}
Serial.print(StrContains("hello", xxx));
}
void loop(){}


x
