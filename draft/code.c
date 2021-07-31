int inches = 0;

int cm = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // 清除触发器
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // 设置触发针高状态10微秒
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  //读取反射针并且以微秒为单位返回声波传播时间
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);

}

void loop()
{
  // 以厘米为单位测量ping时间
  cm = 0.01723 * readUltrasonicDistance(7, 7);
  //除以2.54转换为英寸
  inches = (cm / 2.54);
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.println("cm");
  delay(100); // 等待100毫秒(s)
}