# SYSTEM_STICK_DEMO
SETUP TIMER1 2.097152s
1:Định nghĩa của Tick và Tính toán Thời gian:
tick_t được định nghĩa là kiểu dữ liệu uint32_t hoặc uint16_t tùy thuộc vào cấu hình (32-bit hoặc không).
TICK_PER_MS và TICK_PER_SEC xác định số lượng ticks trong một milisecond và một giây tương ứng. Trong ví dụ TICK_PER_MS = 1 và TICK_PER_SEC = 1024.
2:Tính Tick từ thời gian: 
Để tính số tick tương ứng với một khoảng thời gian nhất định, ta nhân khoảng thời gian đó (trong ms hoặc s) với TICK_PER_MS hoặc TICK_PER_SEC.
Ví dụ, để tính số tick cho 2.097152 giây, bạn nhân 2.097152 với TICK_PER_SEC (1024).

1:Chuyển đổi 2.097152 Giây sang Ticks:
2.097152 giây × 1024 ticks/giây = 2147.819008 ticks.
Tuy nhiên, vì tick_t là một kiểu dữ liệu nguyên, giá trị này sẽ được làm tròn xuống (nếu cần).
2:Ứng dụng trong SysTick:
Ta có thể sử dụng giá trị tick này trong các hàm như Tick_Is_Over để kiểm tra xem liệu một khoảng thời gian 2.097152 giây đã trôi qua hay chưa.
Hàm Tick_Is_Over sẽ so sánh giá trị tick hiện tại (lấy từ Tick_Get()) với giá trị tick đã tính toán để xác định xem khoảng thời gian đã kết thúc hay chưa.
