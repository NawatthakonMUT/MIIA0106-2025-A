#include <iostream>     // ใช้สำหรับคำสั่งรับค่าและแสดงผล เช่น cin, cout
#include <string>       // ใช้สำหรับตัวแปรชนิด string เพื่อเก็บข้อความ
#include <iomanip>      // ใช้สำหรับจัดรูปแบบตัวเลข เช่น setprecision()
#include <limits>       // ใช้สำหรับ numeric_limits เพื่อเคลียร์บัฟเฟอร์

int main()
{
    std::string StudentID;   // ประกาศตัวแปรเก็บรหัสนักศึกษา (แบบข้อความ)
    std::string name;        // ประกาศตัวแปรเก็บชื่อ
    float score;             // ประกาศตัวแปรเก็บคะแนน
    std::string grade;       // ประกาศตัวแปรเก็บเกรดตัวอักษร

    // ----------- รับค่า StudentID พร้อมตรวจสอบว่าเป็นตัวเลขล้วน -----------
    while (true) // วนลูปจนกว่าจะกรอกข้อมูลถูกต้อง
    {
        std::cout << "Enter StudentID : "; // ขอให้ป้อนรหัสนักศึกษา
        if (std::cin >> StudentID) // รับค่าลงใน StudentID
        {
            bool isDigit = true; // ตัวแปรเตรียมตรวจสอบว่ามีแต่ตัวเลขหรือไม่

            // ตรวจสอบอักขระทุกตัวใน StudentID ว่าเป็นตัวเลขหรือไม่
            for (char c : StudentID)
            {
                if (!std::isdigit(static_cast<unsigned char>(c))) // ถ้าเจอไม่ใช่เลข
                {
                    isDigit = false; // ตั้งค่าว่าไม่ใช่ตัวเลขทั้งหมด
                    break;           // หยุดการตรวจสอบ
                }
            }

            if (isDigit) // ถ้าเป็นตัวเลขล้วน
                break;   // ออกจากลูปได้เลย
            else
                std::cout << "Invalid StudentID. Digits only!\n"; // แจ้งเตือน
        }
        else // กรณีผู้ใช้ใส่อะไรผิดจนทำให้ cin error
        {
            std::cout << "Invalid input.\n";
            std::cin.clear(); // เคลียร์สถานะ error ของ cin
        }

        // ล้างข้อมูลค้างในบัฟเฟอร์ เพื่อเตรียมรับค่าครั้งถัดไป
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // เคลียร์บัฟเฟอร์อีกครั้งเพื่อให้ getline ทำงานได้ถูกต้อง
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // ------------------------ รับค่าชื่อผู้เรียน ------------------------
    std::cout << "Enter Name: "; // แสดงข้อความให้ป้อนชื่อ
    std::getline(std::cin, name); // ใช้ getline รับข้อความทั้งบรรทัด (รองรับเว้นวรรค)

    // ------------------------ รับคะแนนพร้อมตรวจสอบความถูกต้อง ------------------------
    while (true) // วนลูปเพื่อให้ได้คะแนนที่ถูกต้องเท่านั้น
    {
        std::cout << "Enter score (0 - 100): "; // ขอให้ป้อนคะแนน
        if (std::cin >> score) // รับคะแนน
        {
            if (score >= 0 && score <= 100) // ตรวจสอบว่าคะแนนอยู่ในช่วงที่กำหนดหรือไม่
            {
                break; // คะแนนถูกต้อง จบการรับข้อมูล
            }
            else
            {
                std::cout << "Error: The score must be between 0 and 100 only!\n"; // แจ้งเตือน
            }
        }
        else // กรณีป้อนค่าไม่ใช่ตัวเลข
        {
            std::cout << "Error: must be number only!\n"; // แจ้งเตือน
            std::cin.clear(); // เคลียร์สถานะ error จาก cin
        }

        // ล้างบัฟเฟอร์เพื่อเตรียมรับค่าครั้งถัดไป
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // ------------------------ คำนวณเกรดจากคะแนน ------------------------
    if (score >= 90) grade = "A";      // คะแนน 90 - 100 = A
    else if (score >= 80) grade = "B"; // คะแนน 80 - 89  = B
    else if (score >= 70) grade = "C"; // คะแนน 70 - 79  = C
    else if (score >= 60) grade = "D"; // คะแนน 60 - 69  = D
    else grade = "F";                  // ต่ำกว่า 60 = F

    // ------------------------ แสดงผลรายงานข้อมูล ------------------------
    std::cout << "\n----------Student Report----------\n"; // ส่วนหัวรายงาน
    std::cout << "StudentID: " << StudentID << "\n";       // แสดงรหัสนักศึกษา
    std::cout << "Name: " << name << "\n";                 // แสดงชื่อ
    std::cout << "Score: " << score << "\n";               // แสดงคะแนน
    std::cout << "Grade: " << grade << "\n";               // แสดงเกรด

    return 0; // คืนค่า 0 เพื่อบอกว่าโปรแกรมจบปกติ
}
