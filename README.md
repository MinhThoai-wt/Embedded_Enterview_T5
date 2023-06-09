# Embedded_Enterview_T5

<details>
  <summary> BUỔI 1. COMPLIER </summary>
  
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

</details>

<details>
  <summary> BUỔI 2. PHÂN VÙNG BỘ NHỚ </summary>

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

</details>

<details>
  <summary> BUỔI 3. MACRO_INLINE FUNCTION </summary>
  
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

</details>

<details>
  <summary> BUỔI 4. THAO TÁC BIT </summary>

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

</details>

<details>
  <summary> BUỔI 5. STRUCT _ UNION </summary>

# Buổi 5. Struct - Union

Về mặt ý nghĩa, struct và union cơ bản giống nhau. Tuy nhiên, về mặt lưu trữ trong bộ nhớ, chúng có sự khác biệt rõ rệt như sau:

•	Struct: Dữ liệu của các thành viên của struct được lưu trữ ở những vùng nhớ khác nhau. Do đó kích thước của 1 struct tối thiểu bằng kích thước các thành viên cộng lại tại vì còn phụ thuộc vào bộ nhớ đệm (struct padding)

•	Union : Dữ liệu các thành viên sẽ dùng chung 1 vùng nhớ. Kích thước của union được tính là kích thước lớn nhất của kiểu dữ liệu trong union. Việc thay đổi nội dung của 1 thành viên sẽ dẫn đến thay đổi nội dung của các thành viên khác.

</details>

<details>
  <summary> BUỔI 6. STATIC - EXTERN - POINTER </summary>

# Buổi 6. Static - Extern
 
## Biến Static gồm:
 
– Biến static cục bộ: Khi 1 biến cục bộ được khai báo với từ khóa static. Biến sẽ chỉ được khởi tạo 1 lần duy nhất và tồn tại suốt thời gian chạy chương trình. Giá trị của nó không bị mất đi ngay cả khi kết thúc hàm. Tuy nhiên khác với biến toàn cục có thể gọi trong tất cả mọi nơi trong chương trình, thì biến cục bộ static chỉ có thể được gọi trong nội bộ hàm khởi tạo ra nó. Mỗi lần hàm được gọi, giá trị của biến chính bằng giá trị tại lần gần nhất hàm được gọi.

– Biến static toàn cục: Biến toàn cục static sẽ chỉ có thể được truy cập và sử dụng trong File khai báo nó, các File khác không có cách nào truy cập được. 

## Extern 

Dùng để gọi đến biến nằm ở file khác, thư viện khác

</details>

<details>
  <summary> BUỔI 7. POINTER </summary>

# Buổi 7. Pointer

## Khái niệm con trỏ: 

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

## Con trỏ hàm

Con trỏ hàm là một biến mà giá trị của nó là địa chỉ của một hàm. Bằng cách sử dụng con trỏ hàm, bạn có thể thực hiện các hoạt động như gọi hàm, truyền hàm như tham số cho các hàm khác và lưu trữ các hàm trong cấu trúc dữ liệu.

Để khai báo một con trỏ hàm, bạn cần chỉ định kiểu dữ liệu của hàm mà con trỏ sẽ trỏ đến. Cú pháp khai báo con trỏ hàm như sau:

        scss
        Copy code
        return_type (*pointer_name)(parameter_list);
        Trong đó:

  + return_type là kiểu dữ liệu của giá trị trả về của hàm.
  
  + pointer_name là tên của con trỏ hàm.
  
  + parameter_list là danh sách tham số của hàm.

## Con trỏ "void"

Trong ngôn ngữ lập trình C, con trỏ void (void pointer), còn được gọi là con trỏ không kiểu (generic pointer), là một loại con trỏ đặc biệt có thể trỏ đến bất kỳ kiểu dữ liệu nào. Một con trỏ void không biết đến kiểu dữ liệu của đối tượng mà nó trỏ đến. Điều này cho phép bạn truyền con trỏ void như một tham số cho các hàm hoặc lưu trữ địa chỉ của bất kỳ đối tượng nào trong một cấu trúc dữ liệu chung.

Để khai báo một con trỏ void, bạn sử dụng từ khóa void như kiểu dữ liệu:

        void *pointer_name;
        
# Point to Point

Trong ngôn ngữ lập trình C, "point to point" (con trỏ tới con trỏ) là khái niệm để mô tả việc sử dụng một con trỏ để trỏ tới một con trỏ khác. Nghĩa là, thay vì trực tiếp trỏ tới một giá trị, con trỏ thứ hai trỏ tới địa chỉ của con trỏ đầu tiên. Điều này cho phép ta truy cập đến giá trị mà con trỏ thứ hai đang trỏ đến.

Để khai báo một con trỏ tới con trỏ trong C, ta sử dụng dấu sao * hai lần:

          int **ptr_to_ptr;

</details>


<details>
  <summary> BUỔI 9. CLASS (C++) </summary>

# Buổi 9. CLASS (C++)

1. Class là gì?
   
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
</details>

<details>
  <summary> BUỔI 10. OPP </summary>
  
# Buổi 10. OPP

## Đặc tính của lập trình hướng đối tượng:

Có 4 đặc tính quan trọng của lập trình hướng đối tượng trong C++ mà chúng ta cần nắm vững sau đây.
 
- **Inheritance (Tính kế thừa )** trong lập trình hướng đối tượng có ý nghĩa, một class có thể kế thừa các thuộc tính của một class khác đã tồn tại trước đó.

Khi một class con được tạo ra bởi việc kế thừa thuộc tính của class cha thì chúng ta sẽ gọi class con đó là subclass trong C++, và class cha chính là superclass trong C++.

- **Abstraction (Tính trừu tượng)** trong lập trình hướng đối tượng là một khả năng mà chương trình có thể bỏ qua sự phức tạp bằng cách tập trung vào cốt lõi của thông tin cần xử lý.

Điều đó có nghĩa, bạn có thể xử lý một đối tượng bằng cách gọi tên một phương thức và thu về kết quả xử lý, mà không cần biết làm cách nào đối tượng đó được các thao tác trong class.

Ví dụ đơn giản, bạn có thể nấu cơm bằng nồi cơm điện bằng cách rất đơn giản là ấn công tắc nấu, mà không cần biết là bên trong cái nồi cơm điện đó đã làm thế nào mà gạo có thể nấu thành cơm.

- **Polymorphism (Tính đa hình)** trong lập trình hướng đối tượng là một khả năng mà một phương thức trong class có thể đưa ra các kết quả hoàn toàn khác nhau, tùy thuộc vào dữ liệu được xử lý.

Ví dụ đơn giản, cùng là một class quản lý dữ liệu là các con vật, thì hành động sủa hay kêu của chúng được định nghĩa trong class sẽ cho ra kết quả khác nhau, ví dụ nếu là con mèo thì kêu meo meo, còn con chó thì sủa gâu gâu chẳng hạn.

- **Encapsulation (Tính đóng gói)** trong lập trình hướng đối tượng có ý nghĩa không cho phép người sử dụng các đối tượng thay đổi trạng thái nội tại của một đối tượng, mà chỉ có phương thức nội tại của đối tượng có thể thay đổi chính nó.

Điều đó có nghĩa, dữ liệu và thông tin sẽ được đóng gói lại, giúp các tác động bên ngoài một đối tượng không thể làm thay đổi đối tượng đó, nên sẽ đảm bảo tính toàn vẹn của đối tượng, cũng như giúp dấu đi các dữ liệu thông tin cần được che giấu.

Ví dụ đơn giản, khi bạn dùng một cái iphone, bạn không thể thay đổi các cấu trúc bên trong của hệ điều hành iOS, mà chỉ có Apple mới có thể làm được điều này thôi.
 
# Namespace là gì?

**Tình huống:**

Khi đang lập trình trong một file A bạn include 2 file B và C, nhưng 2 file này có cùng định nghĩa một hàm function() giống nhau về tên và tham số truyền vào, nhưng xử lý của mỗi hàm ở mỗi file là khác nhau, vấn đề đặt ra là code làm sao để trình biên dịch hiểu được khi nào bạn muốn gọi function của file B, khi nào bạn muốn gọi function của file C. Khi gọi hàm function() ở file A, trình biên dịch sẽ không biết được hàm function() bạn muốn gọi là hàm được định nghĩa ở file B hay file C. Vì vậy trình biên dịch chương trình sẽ báo lỗi.

**Định nghĩa:**

Namespace là từ khóa trong C++ được sử dụng để định nghĩa một phạm vi nhằm mục đích phân biệt các hàm, lớp, biến, ... cùng tên trong các thư viện khác nhau.

# Template trong C++ là gì?

•	Template (khuôn mẫu) là một từ khóa trong C++, và là một kiểu dữ liệu trừu tượng tổng quát hóa cho các kiểu dữ liệu int, float, double, bool...

•	Template trong C++ có 2 loại đó là function template & class template.

•	Template giúp người lập trình định nghĩa tổng quát cho hàm và lớp thay vì phải nạp chồng (overloading) cho từng hàm hay phương thức với những kiểu dữ liệu khác nhau.

</details>

<details>
  <summary> BUỔI 11. VECTOR </summary>
  
# Buổi 11. VECTOR

## Vector là gì?

Giống như là mảng (array), vector trong C++ là một đối tượng dùng để chứa các đối tượng khác, và các đối tượng được chứa này cũng được lưu trữ một cách liên tiếp trong vector.

Tuy nhiên, nếu như số lượng phần tử (size) của một mảng là cố định, thì ở vector, nó hoàn toàn có thể thay đổi trong suốt quá trình làm việc của chương trình

**Modifiers**

1.	push_back(): Hàm đẩy một phần tử vào vị trí sau cùng của vector. Nếu kiểu của đối tượng được truyền dưới dạng tham số trong push_back() không giống với kiểu của vector thì sẽ bị ném ra.

ten-vector.push_back(ten-cua-phan-tu);

2.	assign(): Nó gán một giá trị mới cho các phần tử vector bằng cách thay thế các giá trị cũ.

ten-vector.assign(int size, int value);

3.	pop_back(): Hàm pop_back () được sử dụng để xóa đi phần tử cuối cùng một vector.

4.	insert(): Hàm này chèn các phần tử mới vào trước phần tử trước vị trí được trỏ bởi vòng lặp. Chúng ta cũng có thể chuyển một số đối số thứ ba, đếm số lần phần tử được chèn vào trước vị trí được trỏ.
 
5.	erase(): Hàm được sử dụng để xóa các phần tử tùy theo vị trí vùng chứa

6.	emplace(): Nó mở rộng vùng chứa bằng cách chèn phần tử mới vào

7.	emplace_back(): Nó được sử dụng để chèn một phần tử mới vào vùng chứa vector, phần tử mới sẽ được thêm vào cuối vector

8.	swap(): Hàm được sử dụng để hoán đổi nội dung của một vector này với một vector khác cùng kiểu. Kích thước có thể khác nhau.

9.	clear(): Hàm được sử dụng để loại bỏ tất cả các phần tử của vùng chứa vector.

## Biến Auto

Trong ngôn ngữ lập trình C++, từ khóa "auto" được sử dụng để khai báo biến với kiểu dữ liệu tự động. Khi sử dụng "auto", trình biên dịch sẽ suy luận kiểu dữ liệu của biến dựa trên giá trị được gán cho nó trong quá trình khởi tạo.

Ví dụ, ta có một đoạn mã như sau:

      cpp
      Copy code
      auto x = 10;   // x được suy luận là kiểu int
      auto y = 3.14; // y được suy luận là kiểu double
      auto z = "Hello, world!"; // z được suy luận là kiểu const char*

Trong ví dụ trên, biến "x" được suy luận là kiểu "int" vì giá trị khởi tạo là một số nguyên. Biến "y" được suy luận là kiểu "double" vì giá trị khởi tạo là một số thực. Biến "z" được suy luận là một con trỏ "const char*" vì giá trị khởi tạo là một chuỗi ký tự.

Từ khóa "auto" giúp rút ngắn cú pháp khi khai báo biến và giúp tự động thích ứng với kiểu dữ liệu của giá trị được gán cho biến, tạo ra mã nguồn dễ đọc và linh hoạt hơn. Tuy nhiên, việc sử dụng "auto" cần cẩn thận để tránh gây nhầm lẫn trong mã nguồn và làm giảm tính rõ ràng của kiểu dữ liệu trong một số trường hợp.

## Map trong C++

Trong ngôn ngữ lập trình C++, kiểu dữ liệu "map" là một cấu trúc dữ liệu được cung cấp bởi thư viện chuẩn STL (Standard Template Library). "map" là một dạng cấu trúc dữ liệu ánh xạ (associative container), còn được gọi là "bảng băm" (hash table) hoặc "cấu trúc từ điển" (dictionary).

Một "map" trong C++ là một tập hợp các cặp key-value (khóa-giá trị), trong đó mỗi khóa là duy nhất và liên kết với một giá trị. "map" tự động duy trì sự sắp xếp các khóa theo thứ tự tăng dần, do đó, việc truy cập các phần tử trong "map" sẽ được thực hiện một cách hiệu quả theo thứ tự này.

Cú pháp chung để khai báo một "map" trong C++ như sau:

        std::map<Key, Value> mapName;
        Ở đây, "Key" là kiểu dữ liệu của khóa và "Value" là kiểu dữ liệu của giá trị.

Các phép toán chính trên "map" bao gồm:

- Thêm một cặp key-value vào "map" sử dụng toán tử [] hoặc hàm insert().
  
- Truy cập giá trị của một khóa bằng cách sử dụng toán tử [].
  
- Xóa một phần tử khỏi "map" bằng cách sử dụng hàm erase().
  
- Duyệt qua tất cả các phần tử trong "map" bằng vòng lặp for-each hoặc iterator.
  
- Với "map", bạn có thể tìm kiếm, thêm, truy cập và xóa các phần tử theo khóa một cách hiệu quả. Đặc điểm quan trọng của "map" là không cho phép khóa trùng lặp và tự động sắp
xếp các phần tử theo khóa.

</details>

<details>
  <summary> BUỔI 12. HÀM ẢO </summary>
  
# Buổi 12. HÀM ẢO

**Hàm ảo (virtual function)** là một hàm thành viên trong lớp cơ sở mà lớp dẫn xuất khi kế thừa cần phải định nghĩa lại.

Hàm ảo được sử dụng trong lớp cơ sở khi cần đảm bảo hàm ảo đó sẽ được định nghĩa lại trong lớp dẫn xuất. Việc này rất cần thiết trong trường hợp con trỏ có kiểu là lớp cơ sở trỏ đến đối tượng của lớp dẫn xuất.
 
Hàm ảo là một phần không thể thiếu để thể hiện tính đa hình trong kế thừa được hỗ trợ bởi nguồn ngữ C++.

**Lưu ý:** Con trỏ của lớp cơ sở có thể chứa địa chỉ của đối tượng thuộc lớp dẫn xuất, nhưng ngược lại thì không được.

Hàm ảo chỉ khác hàm thành phần thông thường khi được gọi từ một con trỏ. Sử dụng hàm ảo khi muốn con trỏ đang trỏ tới đối tượng của lớp nào thì hàm thành phần của lớp đó sẽ được gọi mà không xem xét đến kiểu của con trỏ.

</details>






    

     
     
    
    

     
     

























