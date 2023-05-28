# Embedded_Enterview_T5
# Buổi 1. Complier

Complier là quá trình chuyển đổi từ ngôn ngữ bậc cao (NNBC) (C/C++, Pascal, Java, C#…) sang ngôn ngữ đích (ngôn ngữ máy) để máy tính có thể hiểu và thực thi. Ngôn ngữ lập trình C là một ngôn ngữ dạng biên dịch. Chương trình được viết bằng C muốn chạy được trên máy tính phải trải qua một quá trình biên dịch để chuyển đổi từ dạng mã nguồn sang chương trình dạng mã thực thi. Quá trình được chia ra làm 4 giai đoạn chính:

•	Giai đoạn tiền xử lý (Pre-processor)

•	Giai đoạn dịch NNBC sang Asembly (Compiler)

•	Giai đoạn dịch asembly sang ngôn ngữ máy (Asember)

•	Giai đoạn liên kết (Linker)

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


