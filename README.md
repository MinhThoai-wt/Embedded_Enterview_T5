# Embedded_Enterview_T5
# Buổi 1. Complier

Complier là quá trình chuyển đổi từ ngôn ngữ bậc cao (NNBC) (C/C++, Pascal, Java, C#…) sang ngôn ngữ đích (ngôn ngữ máy) để máy tính có thể hiểu và thực thi. Ngôn ngữ lập trình C là một ngôn ngữ dạng biên dịch. Chương trình được viết bằng C muốn chạy được trên máy tính phải trải qua một quá trình biên dịch để chuyển đổi từ dạng mã nguồn sang chương trình dạng mã thực thi. Quá trình được chia ra làm 4 giai đoạn chính:

•	Giai đoạn tiền xử lý (Pre-processor)

•	Giai đoạn dịch NNBC sang Asembly (Compiler)

•	Giai đoạn dịch asembly sang ngôn ngữ máy (Asember)

•	Giai đoạn liên kết (Linker)

![Ảnh chụp màn hình 2023-05-27 192617](https://github.com/MinhThoai-wt/Embedded_Enterview_T5/assets/133029271/442333e5-791a-4e2c-a701-8d5be17959e9)





1. Giai đoạn tiền xử lý – Preprocessor

•	Nhận mã nguồn

•	Xóa bỏ tất cả chú thích, comments của chương trình

•	Chỉ thị tiền xử lý (bắt đầu bằng #) cũng được xử lý

Ví dụ: chỉ thị #include cho phép ghép thêm mã chương trình của một tệp tiêu để vào mã nguồn cần dịch. Các hằng số được định nghĩa bằng #define sẽ được thay thế bằng giá trị cụ thể tại mỗi nơi sử dụng trong chương trình.

2. Giai đoạn dịch Ngôn Ngữ Bậc Cao sang Assembly

•	Phân tích cú pháp (syntax) của mã nguồn NNBC

•	Chuyển chúng sang dạng mã Assembly là một ngôn ngữ bậc thấp (hợp ngữ) gần với tập lệnh của bộ vi xử lý.

3. Giai đoạn dịch Assembly

•	Dich chương trình sang mã máy 0 và 1

•	Một tệp mã máy (.obj) sinh ra trong hệ thống sau đó.

4. Giai đoạn Linker

•	Trong giai đoạn này mã máy của một chương trình dịch từ nhiều nguồn (file .c hoặc file thư viện .lib) được liên kết lại với nhau để tạo thành chương trình đích duy nhất

•	Mã máy của các hàm thư viện gọi trong chương trình cũng được đưa vào chương trình cuối trong giai đoạn này.

# Buổi 2. Phân vùng bộ nhớ

1. Các vùng bộ nhớ

•	Text :

– Quyền truy cập chỉ Read và nó chưa lệnh để thực thi nên tránh sửa đổi instruction.

– Chứa khai báo hằng số trong chương trình (.rodata)

•	Data:

– Quyền truy cập là read-write.

– Chứa biến toàn cục or biến static với giá trị khởi tạo khác không.

– Được giải phóng khi kết thúc chương trình.

•	Bss:

– Quyền truy cập là read-write.

– Chứa biến toàn cục or biến static với giá trị khởi tạo bằng không or không khởi tạo.

– Được giải phóng khi kết thúc chương trình.

•	Stack:

– Quyền truy cập là read-write.

– Được sử dụng cấp phát cho biến local, input parameter của hàm,…

– Sẽ được giải phóng khi ra khỏi block code/hàm

•	Heap:

– Quyền truy cập là read-write.

– Được sử dụng để cấp phát bộ nhớ động như: Malloc, Calloc, …

– Sẽ được giải phóng khi gọi hàm free,…

2. So sánh Stack và Heap

•	Bộ nhớ Heap và bộ nhớ Stack bản chất đều cùng là vùng nhớ được tạo ra và lưu trữ trong RAM khi chương trình được thực thi.

•	Bộ nhớ Stack được dùng để lưu trữ các biến cục bộ trong hàm, tham số truyền vào... Truy cập vào bộ nhớ này rất nhanh và được thực thi khi chương trình được biên dịch.

•	Bộ nhớ Heap được dùng để lưu trữ vùng nhớ cho những biến con trỏ được cấp phát động bởi các hàm malloc - calloc - realloc (trong C)

•	Kích thước vùng nhớ:

Stack: kích thước của bộ nhớ Stack là cố định, tùy thuộc vào từng hệ điều hành, ví dụ hệ điều hành Windows là 1 MB, hệ điều hành Linux là 8 MB (lưu ý là con số có thể khác tùy thuộc vào kiến trúc hệ điều hành của bạn).

Heap: kích thước của bộ nhớ Heap là không cố định, có thể tăng giảm do đó đáp ứng được nhu cầu lưu trữ dữ liệu của chương trình.

•	Đặc điểm vùng nhớ:

Stack: vùng nhớ Stack được quản lý bởi hệ điều hành, dữ liệu được lưu trong Stack sẽ tự động hủy khi hàm thực hiện xong công việc của mình.

Heap: Vùng nhớ Heap được quản lý bởi lập trình viên (trong C hoặc C++), dữ liệu trong Heap sẽ không bị hủy khi hàm thực hiện xong, điều đó có nghĩa bạn phải tự tay hủy vùng nhớ bằng câu lệnh free (trong C), và delete hoặc delete [] (trong C++), nếu không sẽ xảy ra hiện tượng rò rỉ bộ nhớ. 

![Ảnh chụp màn hình 2023-05-28 174924](https://github.com/MinhThoai-wt/Embedded_Enterview_T5/assets/133029271/76844c88-64db-47fd-bfba-2e082b405190)

# Buổi 3. Macro_ Inline Function

1. Macro:

•	Được xử lý bởi preprocessor

•	Thay thế đoạn code được khai báo macro vào bất cứ chỗ nào xuất hiện macro đó

•	VD: #define SUM(a,b)     (a+b)

•	Preprocessor khi gặp bất kỳ lời gọi SUM(first+last) nào thì thay ngay bằng (first+last)

2. Inline

•	Được xử lý bởi compiler

•	Được khai báo với từ khóa inline

•	Khi compiler thấy bất kỳ chỗ nào xuất hiện inline function, nó sẽ thay thế chỗ đó bởi định nghĩa của hàm đã được compile tương ứng. –> Phần được thay thế không phải code mà là đoạn code đã được compile

3. Hàm bình thường

•	Khi thấy hàm được gọi, compiler sẽ phải lưu con trỏ chương trình PC hiện tại vào stack; chuyển PC tới hàm được gọi, thực hiện hàm đó xong và lấy kết quả trả về; sau đó quay lại vị trí 
ban đầu trong stack trước khi gọi hàm và tiếp tục thực hiện chương trình.

•	Như có thể thấy, các này khiến chương trình tốn thời gian hơn là chỉ cần thay thế đoạn code đã được compile (cách của inline function)

4. So sánh

•	Macro đơn giản là chỉ thay thế đoạn code macro vào chỗ được gọi trước khi được biên dịch

•	Inline thay thế đoạn mã code đã được biên dịch vào chỗ được gọi

•	Hàm bình thường phải tạo một function call, lưu địa chỉ trước khi gọi hàm vào stack sau đó mới thực hiện hàm và sau cùng là quay trở về địa chỉ trên stack trước khi gọi hàm và thực hiện tiếp chương trình

•	Macro khiến code trở nên dài hơn rất nhiều so với bình thường nhưng thời gian chạy nhanh.

•	Hàm inline cũng khiến code dài hơn, tuy nhiên nó làm giảm thời gian chạy chương trình

•	Hàm bình thường sẽ phải gọi function call nên tốn thời gian hơn inline function nhưng code ngắn gọn hơn.

# Buổi 4. Thao tác Bit

AND: x=y & z;

![image](https://github.com/MinhThoai-wt/Embedded_Enterview_T5/assets/133029271/1d37cefe-3834-4194-9e9c-40463a3904de)

![image](https://github.com/MinhThoai-wt/Embedded_Enterview_T5/assets/133029271/66ffd02c-169b-4ade-ae6f-504f36f0f902)

NOT: x=~y;

![image](https://github.com/MinhThoai-wt/Embedded_Enterview_T5/assets/133029271/af8d5aa9-ed86-4aa2-93f3-c630159b5cc3)

![image](https://github.com/MinhThoai-wt/Embedded_Enterview_T5/assets/133029271/2f71ba8c-00c5-4c84-91df-d92592f81fee)

OR: x=y | z;

![image](https://github.com/MinhThoai-wt/Embedded_Enterview_T5/assets/133029271/2eaeac7a-aa77-4319-8b2d-a6606c2323ae)

![image](https://github.com/MinhThoai-wt/Embedded_Enterview_T5/assets/133029271/d5681a9e-5816-4e52-bbfc-3ba57139f239)

XOR: x = y ^ z;

![image](https://github.com/MinhThoai-wt/Embedded_Enterview_T5/assets/133029271/42866a9e-fdd2-4af2-8c81-c84b2cbc6863)

![image](https://github.com/MinhThoai-wt/Embedded_Enterview_T5/assets/133029271/5ef84cf6-2bb3-423b-a9d2-7eae621e57f6)

Dịch Bit: >> (Dịch phải) và << ( Dịch trái )

![image](https://github.com/MinhThoai-wt/Embedded_Enterview_T5/assets/133029271/2752e4fe-25bb-49dc-bef5-d36f5dc89033)

# Buổi 5. Struct - Union

Về mặt ý nghĩa, struct và union cơ bản giống nhau. Tuy nhiên, về mặt lưu trữ trong bộ nhớ, chúng có sự khác biệt rõ rệt như sau:

•	Struct: Dữ liệu của các thành viên của struct được lưu trữ ở những vùng nhớ khác nhau. Do đó kích thước của 1 struct tối thiểu bằng kích thước các thành viên cộng lại tại vì còn phụ thuộc vào bộ nhớ đệm (struct padding)

•	Union : Dữ liệu các thành viên sẽ dùng chung 1 vùng nhớ. Kích thước của union được tính là kích thước lớn nhất của kiểu dữ liệu trong union. Việc thay đổi nội dung của 1 thành viên sẽ dẫn đến thay đổi nội dung của các thành viên khác.

# Buổi 6. Static - Extern - Pointer
 
• Biến Static gồm:
 
– Biến static cục bộ: Khi 1 biến cục bộ được khai báo với từ khóa static. Biến sẽ chỉ được khởi tạo 1 lần duy nhất và tồn tại suốt thời gian chạy chương trình. Giá trị của nó không bị mất đi ngay cả khi kết thúc hàm. Tuy nhiên khác với biến toàn cục có thể gọi trong tất cả mọi nơi trong chương trình, thì biến cục bộ static chỉ có thể được gọi trong nội bộ hàm khởi tạo ra nó. Mỗi lần hàm được gọi, giá trị của biến chính bằng giá trị tại lần gần nhất hàm được gọi.

– Biến static toàn cục: Biến toàn cục static sẽ chỉ có thể được truy cập và sử dụng trong File khai báo nó, các File khác không có cách nào truy cập được. 

•  Extern dùng để gọi đến biến nằm ở file khác, thư viện khác

• Khái niệm con trỏ: 

– Bộ nhớ RAM chứa rất nhiều ô nhớ, mỗi ô nhớ có kích thước 1 byte.

– Mỗi ô nhớ có địa chỉ duy nhất và địa chỉ này được đánh số từ 0 trở đi. Nếu CPU 32 bit thì có 2^32 địa chỉ có thể đánh cho các ô nhớ trong RAM.

![image](https://github.com/MinhThoai-wt/Embedded_Enterview_T5/assets/133029271/e8b7aa97-ba69-4a42-a45c-696b93ba6fe0)

– Khi khai báo biến, trình biên dịch dành riêng một vùng nhớ với địa chỉ duy nhất để lưu biến. Trình biên dịch có nhiệm vụ liên kết địa chỉ ô nhớ đó với tên biến. Khi gọi tên biến, nó sẽ truy xuất tự động đến ô nhớ đã liên kết với tên biến để lấy dữ liệu. Các bạn phải luôn phân biệt giữa địa chỉ bộ nhớ và dữ liệu được lưu trong đó.

![image](https://github.com/MinhThoai-wt/Embedded_Enterview_T5/assets/133029271/b11dde3a-d176-49fe-aae6-324ff91c6b0b)

– Địa chỉ của biến bản chất cũng là một con số thường được biểu diễn ở hệ cơ số 16. Ta có thể sử dụng con trỏ (pointer) để lưu địa chỉ của các biến.

– Trong ngôn ngữ C/C++, con trỏ (pointer) là những biến lưu trữ địa chỉ bộ nhớ của những biến khác.

![image](https://github.com/MinhThoai-wt/Embedded_Enterview_T5/assets/133029271/a3aa91b2-54f4-4ba3-ab2d-d41c1fb579d1)

– Trong hình trên, biến var lưu giá trị 5 có địa chỉ là 0x61ff08. Biến pointVar là biến con trỏ, lưu địa chỉ của biến var (trỏ đến vùng nhớ của biến var), tức là nó lưu giá trị 0x61ff08.

– Con trỏ NULL

  + Con trỏ NULL là con trỏ lưu địa chỉ 0x00000000. Tức địa chỉ bộ nhớ 0, có ý nghĩa đặc biệt, cho biết con trỏ không trỏ vào đâu cả.

     int *p2;//con trỏ chưa khởi tạo, vẫn trỏ đến một vùng nhớ nào đó không xác định
     
     int *p3 = NULL;//con trỏ null không trỏ đến vùng nhớ nào
     
 – Kích thước của con trỏ: ví dụ các khai báo con trỏ sau:
  
        char *p1;
     
        int *p2;
     
        float *p3;
    
        double *p4;
     
     Kích thước của các biến con trỏ có khác nhau không? Con trỏ chỉ lưu địa chỉ nên kích thước của mọi con trỏ là như nhau. Kích thước này phụ thuộc vào môi trường hệ thống máy tính:
         
         Môi trường Windows 32 bit: 4 bytes
         Môi trường Windows 64 bit: 8 bytes

– Một số lưu ý khi sử dụng con trỏ:
     
    + Khi khởi tạo con trỏ NULL
    
    + Chữ NULL phải viết hoa, viết thường null sẽ bị lỗi.
    
        int *p1 = NULL;//đúng
    
        int *p2 = null;//lỗi
    
    + Không nên sử dụng con trỏ khi chưa được khởi tạo

    + Kết quả tính toán có thể sẽ phát sinh những lỗi không lường trước được nếu chưa khởi tạo con trỏ.

# Buổi 9. C++ (Class)

1. Class là gì?
2. 
Class hay lớp là một mô tả trừu tượng (abstract) của nhóm các đối tượng (object) có cùng bản chất, ngược lại mỗi một đối tượng là một thể hiện cụ thể (instance) cho những mô tả trừu tượng đó. Một class trong C++ sẽ có các đặc điểm sau:

•	Một class bao gồm các thành phần dữ liệu (thuộc tính hay property) và các phương thức (hàm thành phần hay method).

•	Class thực chất là một kiểu dữ liệu do người lập trình định nghĩa.

•	Trong C++, từ khóa class sẽ chỉ điểm bắt đầu của một class sẽ được cài đặt.

Ví dụ về một class đơn giản, class Car. Một chiếc xe hơi vậy thì sẽ có chung những đặc điểm là đều có vô lăng, có bánh xe nhiều hơn 3, có động cơ… Đó là một class, một cái model hay mẫu mà người ta đã quy định là nếu đúng như vậy thì nó là xe hơi. Nhưng mà xe thì có thể có nhiều hãng khác nhau, BMW, Vinfast, Toyota… Thì mỗi hãng xe lại có những model xe khác nhau nhưng chúng đều là xe hơi. Vậy thì trong lập trình cũng vậy, class là quy định ra một mẫu, một cái model mà các thể hiện của nó (instance) hay đối tượng (object) phải tuân theo.


Khai báo class và sử dụng class

Ví dụ một class cơ bản:

     class Person { public:
     
     string firstName; // property string lastName; // property int age; // property
     
     void fullname() { // method
     
     cout << firstName << ' ' << lastName;
     
     }
     
     };
 
Cú pháp tạo object của một class và sử dụng các thuộc tính và phương thức:

     Person person; 
     
     person.firstName = "Khiem"; 
     
     person.lastName = "Le";
     
     person.fullname(); // sẽ in ra màn hình là "Khiem Le"

2. Access modifiers & properties declaration
   
Access modifier là phạm vi truy cập của các thuộc tính và phương thức sẽ được khai báo bên dưới nó. Có 3 phạm vi truy cập trong C++ là public, private và protected.

•	Các thuộc tính và phương thức khai báo public thì có thể được truy cập trực tiếp thông qua instance của class đó. Các thuộc tính nên khai báo là public nếu bạn không có ràng buộc điều kiện trước khi gán (người dùng có thể thoải mái gán giá trị) hoặc bạn không cần xử lý trước khi trả về giá trị thuộc tính;

•	Các thuộc tính private thường được sử dụng khi bạn không mong muốn người khác có thể tùy ý gán giá trị hoặc là bạn muốn xử lý trước khi trả về giá trị.
•	Đối với protected, các phương thức và thuộc tính chỉ có thể truy cập qua các class kế thừa nó hoặc chính nó.

Ví dụ của access modifier:

     class MyClass
     
     {
     
     public:
     
     int public_property;
     
     private:
     
     int _private_property;
     
     };

 
3. Method declaration
   
Phương thức cũng giống như một hàm bình thường.

Đối với phương thức thì có hai cách định nghĩa thi hành: định nghĩa thi hành trong lúc định nghĩa class và định nghĩa thi hành bên ngoài class.

Định nghĩa thi hành bên trong class:

     class Animal { public:
     
     string sound;
     
     void makeNoise() { cout << sound;
     }
     
     };
 

Định nghĩa thi hành bên ngoài class:

     class Animal { public:
     
     string sound;
     
     void makeNoise();
     
     };
     
     void Animal::makeNoise() { cout << sound;
     }


 
4. Constructor
5. 
Constructor hay hàm dựng là một hàm đặc biệt, nó sẽ được gọi ngay khi chúng ta khởi tạo một object.

     class Person {
   
     public:
   
     string firstName; string lastName; int age;
     
     Person(string _firstName, string _lastName, int _age)
   
     {
   
     firstName = _firstName; lastName = _lastName; age = _age;
   
     }
     
     void fullname() {
   
     cout << firstName << ' ' << lastName;
   
     }
   
     };





    

     
     
    
    

     
     

























