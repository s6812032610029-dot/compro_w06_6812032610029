#include <stdio.h>  // นำเข้าไลบรารีมาตรฐาน <stdio.h> ซึ่งใช้สำหรับแสดงผลทางหน้าจอ (output) และรับค่าจากผู้ใช้ (input)

// ฟังก์ชันหลักของโปรแกรม เป็นจุดเริ่มต้นที่ระบบจะเริ่มรันโค้ด
int main() {

    // แสดงหัวข้อของโปรแกรม
    printf("หัวข้อ: การเขียนนิพจน์ในรูปย่อ (Short-hand Expression)\n\n");

    // ───────────────────────────────────────
    // ประกาศและกำหนดค่าเริ่มต้นให้ตัวแปรต่าง ๆ
    // เพื่อใช้ในการคำนวณตัวอย่างในแต่ละนิพจน์
    // ───────────────────────────────────────
    double x = 100.0;        // ตัวแปรทศนิยม ใช้ในหลาย expression
    int y = 7;               // จำนวนเต็ม สำหรับใช้ร่วมกับ z และ a
    int z = 3;               // จำนวนเต็ม
    int a = 2;               // จำนวนเต็ม
    double total = 500.0;    // ใช้จำลองยอดรวม
    double price = 100.0;    // ราคาต่อหน่วยสินค้า
    int quantity = 5;        // จำนวนสินค้า
    double discount = 20.0;  // ส่วนลด
    double rate = 5.0;       // อัตรา (เช่น ดอกเบี้ย หรือเปอร์เซ็นต์)
    double score = 85.0;     // คะแนนก่อนหัก
    double penalty = 2.0;    // ค่าปรับต่อความผิดพลาด 1 ครั้ง
    int mistake = 3;         // จำนวนข้อผิดพลาด

    // ───────────────────────────────────────
    // Expression 1: การเขียน x = x - 4.0 ในรูปแบบเต็ม และแบบย่อ
    // ───────────────────────────────────────
    printf("--- 1. x = x - 4.0; ---\n");
    double x_full_1 = x;     // ตัวแปรสำหรับแบบเต็ม
    double x_short_1 = x;    // ตัวแปรสำหรับแบบย่อ

    // แบบเต็ม: ใช้รูปแบบมาตรฐานที่ชัดเจนในการลบค่า
    x_full_1 = x_full_1 - 4.0;
    printf("   แบบเต็ม (x = x - 4.0;): x = %.2f\n", x_full_1);

    // แบบย่อ: เขียนย่อด้วยเครื่องหมาย -= ซึ่งหมายถึง ลบค่าด้านขวาออกจากตัวแปรซ้าย
    x_short_1 -= 4.0;
    printf("   แบบย่อ (x -= 4.0;):    x = %.2f\n", x_short_1);

    // ตรวจสอบว่าค่าหลังคำนวณแบบเต็มและแบบย่อให้ผลเหมือนกันหรือไม่
    printf("   ผลลัพธ์เท่ากัน: %s\n\n", (x_full_1 == x_short_1) ? "True" : "False");

    // ───────────────────────────────────────
    // Expression 2: การคูณค่าคงที่กับตัวแปร x
    // ───────────────────────────────────────
    printf("--- 2. x = 6.5 * x; ---\n");
    double x_full_2 = x;
    double x_short_2 = x;

    x_full_2 = 6.5 * x_full_2;
    printf("   แบบเต็ม (x = 6.5 * x;): x = %.2f\n", x_full_2);

    x_short_2 *= 6.5;  // คูณค่าด้วย 6.5 โดยใช้เครื่องหมาย *=
    printf("   แบบย่อ (x *= 6.5;):    x = %.2f\n", x_short_2);

    printf("   ผลลัพธ์เท่ากัน: %s\n\n", (x_full_2 == x_short_2) ? "True" : "False");

    // ───────────────────────────────────────
    // Expression 3: การใช้ modulo กับนิพจน์คำนวณ
    // ───────────────────────────────────────
    printf("--- 3. x = x %% (y + z * a); ---\n");
    int x_int_full_3 = (int)x;     // แปลง x จาก double เป็น int เพื่อใช้กับ %
    int x_int_short_3 = (int)x;
    int divisor_3 = y + z * a;     // ค่าที่นำมาใช้เป็นตัวหาร: 7 + 3 * 2 = 13

    x_int_full_3 = x_int_full_3 % divisor_3;
    printf("   แบบเต็ม (x = x %% (y + z * a);): x = %d\n", x_int_full_3);

    x_int_short_3 %= divisor_3;
    printf("   แบบย่อ (x %%= (...);):          x = %d\n", x_int_short_3);

    printf("   ผลลัพธ์เท่ากัน: %s\n\n", (x_int_full_3 == x_int_short_3) ? "True" : "False");

    // ───────────────────────────────────────
    // Expression 4: การหารค่าด้วยนิพจน์ที่มี x อยู่ภายใน
    // ───────────────────────────────────────
    printf("--- 4. x = x / (2.0 * x); ---\n");
    double x_full_4 = x;
    double x_short_4 = x;
    double divisor_4 = 2.0 * x;

    if (divisor_4 == 0) {
        printf("   ไม่สามารถหารด้วยศูนย์ได้\n\n");
    } else {
        x_full_4 = x_full_4 / divisor_4;
        x_short_4 /= divisor_4;
        printf("   แบบเต็ม: x = %.4f\n", x_full_4);
        printf("   แบบย่อ:  x = %.4f\n", x_short_4);
        printf("   ผลลัพธ์เท่ากัน: %s\n\n", (x_full_4 == x_short_4) ? "True" : "False");
    }

    // ───────────────────────────────────────
    // Expression 5: การเพิ่มค่าจากการคำนวณเข้าไปในตัวแปร total
    // ───────────────────────────────────────
    printf("--- 5. total = total + (price * quantity - discount); ---\n");
    double total_full_5 = total;
    double total_short_5 = total;
    double value_to_add_5 = price * quantity - discount;

    total_full_5 = total_full_5 + value_to_add_5;
    total_short_5 += value_to_add_5;
    printf("   แบบเต็ม: total = %.2f\n", total_full_5);
    printf("   แบบย่อ:  total = %.2f\n", total_short_5);
    printf("   ผลลัพธ์เท่ากัน: %s\n\n", (total_full_5 == total_short_5) ? "True" : "False");

    // ───────────────────────────────────────
    // Expression 6: การคูณกับอัตราร้อยละ (เปอร์เซ็นต์)
    // ───────────────────────────────────────
    printf("--- 6. x = x * (1 + rate / 100); ---\n");
    double x_full_6 = x;
    double x_short_6 = x;
    double factor_6 = 1 + rate / 100.0;

    x_full_6 = x_full_6 * factor_6;
    x_short_6 *= factor_6;
    printf("   แบบเต็ม: x = %.2f\n", x_full_6);
    printf("   แบบย่อ:  x = %.2f\n", x_short_6);
    printf("   ผลลัพธ์เท่ากัน: %s\n\n", (x_full_6 == x_short_6) ? "True" : "False");

    // ───────────────────────────────────────
    // Expression 7: การหักคะแนนจากความผิดพลาด
    // ───────────────────────────────────────
    printf("--- 7. score = score - (penalty * (mistake + 1)); ---\n");
    double score_full_7 = score;
    double score_short_7 = score;
    double deduction_7 = penalty * (mistake + 1);  // เช่น ผิด 3 ข้อ หัก (2.0 * 4) = 8.0

    score_full_7 = score_full_7 - deduction_7;
    score_short_7 -= deduction_7;
    printf("   แบบเต็ม: score = %.2f\n", score_full_7);
    printf("   แบบย่อ:  score = %.2f\n", score_short_7);
    printf("   ผลลัพธ์เท่ากัน: %s\n\n", (score_full_7 == score_short_7) ? "True" : "False");

    return 0; // จบการทำงานของโปรแกรม โดยคืนค่า 0 กลับไปยังระบบ
}
