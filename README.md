/ ARABIC / عربية /

 مفدمة:
 هذا الكود هو برنامج بسيط لإدارة مكتبة، مكتوب بلغة C++. يستخدم البرنامج مصفوفات متوازية لتخزين بيانات الكتب، ويوفر قائمة تفاعلية من الخيارات التي تسمح للمستخدم بإدارة الكتب بشكل كامل.
​المكونات الأساسية للبرنامج
​يعتمد البرنامج على مجموعة من المتغيرات والمصفوفات العامة التي تُعرّف في بداية الكود لتكون متاحة لجميع الدوال. هذه المكونات هي بمثابة "قاعدة بيانات" بسيطة للبرنامج.
​int bookids[100];: مصفوفة لتخزين معرّفات (IDs) الكتب. المعرّف هو رقم فريد يميّز كل كتاب عن الآخر.
​string booktitles[100];: مصفوفة لتخزين عناوين الكتب.
​string bookauthors[100];: مصفوفة لتخزين أسماء مؤلفي الكتب.
​bool isborrowed[100];: مصفوفة من النوع المنطقي (bool) لتتبع حالة الاستعارة لكل كتاب. القيمة true تعني أن الكتاب مستعار، وfalse تعني أنه متاح.
​int bookcount = 0;: متغير يُستخدم لحساب العدد الإجمالي للكتب الموجودة حاليًا في المكتبة. كلما أُضيف كتاب جديد، تزيد قيمة هذا المتغير، وكلما حُذف كتاب، تنقص قيمته.
​الدوال (Functions) ووظائفها
​البرنامج مُقسّم إلى دوال منفصلة، كل دالة مسؤولة عن تنفيذ مهمة محددة. هذا الأسلوب يسمى البرمجة الإجرائية (procedural programming) ويجعل الكود أكثر تنظيمًا وقابلية للقراءة والصيانة.

​void addbook(): إضافة كتاب جديد

​تُستخدم هذه الدالة لإدخال بيانات كتاب جديد.
​تطلب من المستخدم إدخال معرّف الكتاب.
​تتضمن حلقة while للتحقق من تفرّد المعرّف (uID = true). إذا كان المعرف الذي أدخله المستخدم موجودًا بالفعل في مصفوفة bookids، تُعرض رسالة خطأ ويُطلب منه إدخال معرف آخر. هذا يمنع وجود كتابين بنفس المعرّف.
​بعد التحقق، تطلب الدالة إدخال عنوان الكتاب واسم المؤلف.
​تُخزّن هذه البيانات في المصفوفات المتوازية عند الموقع المشار إليه بـbookcount.
​تُضبط حالة الاستعارة الأولية (isborrowed) على false (متاح).
​أخيرًا، يزيد المتغير bookcount بمقدار واحد ليشير إلى إضافة كتاب جديد.

​void deleteBook(): حذف كتاب

​تُستخدم لحذف كتاب بناءً على معرّفه.
​تطلب الدالة من المستخدم إدخال معرّف الكتاب المراد حذفه.
​تستخدم حلقة for للبحث عن المعرّف في مصفوفة bookids.
​عند العثور على الكتاب، تُستخدم حلقة تكرارية أخرى (for (int j = i; ... )) لإزاحة جميع العناصر التي تقع بعد الكتاب المحذوف خطوة واحدة إلى الأمام. هذا الإجراء يزيل الكتاب من المصفوفات بشكل فعال.
​يُقلل المتغير bookcount بمقدار واحد.
​إذا لم يُعثر على الكتاب، تُعرض رسالة تفيد بأن "الكتاب غير موجود".

​void displayBooks(): عرض كل الكتب

تعرض هذه الدالة معلومات جميع الكتب الموجودة في المكتبة.
​تتحقق أولًا مما إذا كانت المكتبة فارغة (bookcount == 0).
​إذا كانت المكتبة تحتوي على كتب، تستخدم حلقة for للمرور على جميع الكتب وعرض تفاصيل كل منها: المعرّف، العنوان، المؤلف، وحالة الاستعارة (متاح أو غير متاح).
​يُستخدم تعبير شرطي بسيط ((isborrowed[i]==0 ? "available " : "not available ")) لتحويل القيمة المنطقية إلى نص مفهوم.

​void borrowBook(): استعارة كتاب

​تتيح هذه الدالة للمستخدم استعارة كتاب.
​تطلب من المستخدم إدخال معرّف الكتاب المراد استعارته.
​تبحث عن الكتاب في المصفوفات.
​إذا وُجد الكتاب، تتحقق من حالته. إذا كان متاحًا (!isborrowed[i])، تُغيّر حالة isborrowed إلى true وتُعرض رسالة نجاح.
​إذا كان الكتاب مستعارًا بالفعل، تُعرض رسالة توضح أنه "لا يمكن استعارة الكتاب".
​إذا لم يُعثر على الكتاب، تُعرض رسالة "الكتاب غير موجود".

​void returnBook(): إرجاع كتاب

​تعمل هذه الدالة بشكل مشابه لدالة الاستعارة، ولكنها تتيح إرجاع كتاب.
​تطلب معرّف الكتاب المراد إرجاعه.
​تبحث عن الكتاب.
​إذا وُجد الكتاب ووجد أنه مستعار (isborrowed[i])، تُغيّر حالة isborrowed إلى false وتُعرض رسالة نجاح.
​إذا لم يكن الكتاب مستعارًا، تُعرض رسالة تفيد بذلك.
​إذا لم يُعثر على الكتاب، تُعرض رسالة "الكتاب غير موجود".

​void searchbook(): البحث عن كتاب

​تسمح للمستخدم بالبحث عن كتاب باستخدام معرّفه فقط.
​تطلب معرّف الكتاب للبحث.
​تستخدم حلقة for للبحث عن المعرّف.
​إذا وُجد، تعرض جميع معلومات الكتاب وتنهي الحلقة باستخدام break.

​void EditBook(): تعديل بيانات كتاب

​تسمح بتعديل أي من بيانات الكتاب (المعرّف، العنوان، المؤلف).
​تطلب معرّف الكتاب المراد تعديله.
​تبحث عن الكتاب.
​إذا وُجد، تعرض بياناته القديمة أولًا، ثم تطلب من المستخدم إدخال البيانات الجديدة.
​تتضمن الدالة نفس آلية التحقق من تفرّد المعرّف الموجودة في دالة addbook() لضمان عدم تكرار المعرّفات بعد التعديل.

​void Libraryinfo(): معلومات المكتبة

​توفر هذه الدالة إحصائيات سريعة عن المكتبة.
​تستخدم حلقة for للمرور على جميع الكتب وحساب عدد الكتب المستعارة والمتاحة.
​تُعرض إحصائيات عامة تشمل: إجمالي عدد الكتب، عدد الكتب المستعارة، وعدد الكتب المتاحة.


​void DisplayBorrowedBooks(): عرض الكتب المستعارة

​تعرض قائمة بالكتب المستعارة حاليًا فقط.
​تستخدم حلقة for وتتحقق من قيمة isborrowed لكل كتاب.
​إذا كانت القيمة true، تُعرض معلومات الكتاب.
​إذا لم يكن هناك أي كتاب مستعار، تُعرض رسالة تفيد بذلك.

​الدالة الرئيسية main():

​هذه هي نقطة دخول البرنامج.
​تُهيّئ الدالة بعض الكتب الافتراضية في بداية التشغيل. هذا الإجراء يسهل اختبار البرنامج دون الحاجة لإضافة الكتب يدويًا في كل مرة.
​تستخدم حلقة while(true) لإنشاء قائمة مستمرة تُعرض للمستخدم حتى يختار الخروج.
​تُعرض قائمة الخيارات (من 1 إلى 9، و0 للخروج).
​يُستخدم أمر switch لتنفيذ الدالة المناسبة بناءً على اختيار المستخدم.
​الخيار 0 ينهي البرنامج بعبارة شكر.
​في حالة إدخال رقم غير صحيح، تُعرض رسالة خطأ.

​الخلاصة:
​هذا البرنامج هو مثال عملي ممتاز على كيفية استخدام المصفوفات المتوازية لإدارة البيانات المرتبطة ببعضها. رغم بساطته، فإنه يغطي معظم الوظائف الأساسية لنظام إدارة مكتبة صغير.
التحسينات المستقبلية قد تشمل استخدام هياكل البيانات المتقدمة مثل structs أو classes لتجميع بيانات كل كتاب في كائن واحد، مما يجعل الكود أكثر كفاءة وسهولة في الإدارة.

/ English /

Overview:
​This is a simple library management program written in C++. It uses parallel arrays to store different book details such as ID, title, author, and borrowing status. The program provides a menu of options for the user to add, display, borrow, return, search, edit, delete books, or view general library information.

​Core Components of the Program
​The program relies on a set of global variables and arrays defined at the beginning of the code to be accessible by all functions. These components serve as a simple "database" for the program.
​int bookids[100];: An array to store the IDs of the books. An ID is a unique number that identifies each book.
​string booktitles[100];: An array to store the titles of the books.
​string bookauthors[100];: An array to store the authors' names.
​bool isborrowed[100];: A boolean array to track the borrowing status of each book. A value of true means the book is borrowed, and false means it's available.
​int bookcount = 0;: A variable used to count the total number of books currently in the library. This variable increments when a book is added and decrements when a book is deleted.

​Functions and Their Functions
​The program is divided into separate functions, each responsible for performing a specific task. This approach, known as procedural programming, makes the code more organized, readable, and maintainable.

​void addbook(): Add a New Book

​This function is used to add a new book's data.
​It prompts the user to enter the book's ID.
​It includes a while loop to ensure the uniqueness of the ID (uID = true). If the entered ID already exists in the bookids array, an error message is displayed, and the user is asked to enter a different one. This prevents duplicate IDs.
​After validation, the function asks for the book's title and author's name.
​It stores this data in the parallel arrays at the index indicated by bookcount.
​The initial borrowing status (isborrowed) is set to false (available).
​Finally, the bookcount variable is incremented by one to reflect the new book.

​void deleteBook(): Delete a Book

​This function is used to delete a book based on its ID.
​It prompts the user to enter the ID of the book to be deleted.
​It uses a for loop to search for the ID in the bookids array.
​When the book is found, another loop (for (int j = i; ... )) is used to shift all subsequent elements in the arrays one position forward. This effectively removes the targeted book.
​The bookcount variable is decremented by one.
​If the book is not found, a message indicating "Book not found!" is displayed.

​void displayBooks(): Display All Books

​This function displays the information of all books in the library.
​It first checks if the library is empty (bookcount == 0).
​If there are books, it uses a for loop to iterate through all of them and display their details: ID, title, author, and borrowing status (available or not available).
​A simple conditional expression ((isborrowed[i]==0 ? "available " : "not available ")) is used to convert the boolean value to a more human-readable text.

​void borrowBook(): Borrow a Book

​This function allows a user to borrow a book.
​It prompts the user to enter the ID of the book to be borrowed.
​It searches for the book in the arrays.
​If the book is found and is available (!isborrowed[i]), the isborrowed status is changed to true, and a success message is displayed.
​If the book is already borrowed, a message indicating that it cannot be borrowed is shown.
​If the book is not found, a "Book not found" message is displayed.

​void returnBook(): Return a Book

​This function works similarly to the borrow function, but for returning a book.
​It prompts for the ID of the book to be returned.
​It searches for the book.
​If the book is found and is borrowed (isborrowed[i]), the isborrowed status is changed to false, and a success message is shown.
​If the book is not borrowed, a message stating this is displayed.
​If the book is not found, a "Book not found" message is displayed.

​void searchbook(): Search for a Book

​This function allows the user to search for a book using only its ID.
​It prompts for the book ID to search.
​It uses a for loop to find the ID.
​If found, it displays all the book's information and exits the loop using break.

​void EditBook(): Edit Book Information

​This function allows editing any of the book's details (ID, title, author).
​It prompts for the ID of the book to be edited.
​It searches for the book.
​If found, it first displays the old information and then prompts the user to enter the new details.
​The function includes the same ID uniqueness check as the addbook() function to prevent duplicate IDs after the edit.

​void Libraryinfo(): Library Information

​This function provides quick statistics about the library.
​It uses a for loop to iterate through all books and count the number of borrowed and available books.
​It displays general statistics including the total number of books, the number of borrowed books, and the number of available books.

​void DisplayBorrowedBooks(): Display Borrowed Books

​This function displays a list of all books that are currently borrowed.
​It uses a for loop and checks the isborrowed status for each book.
​If the status is true, it displays the book's information.
​If no books are borrowed, it displays a message indicating so.

​The Main Function: main()

​This is the entry point of the program.
​It initializes a few default books at startup to make testing easier.
​It uses a while(true) loop to create a continuous menu that is displayed until the user chooses to exit.
​The menu of options (1 through 9, and 0 to exit) is displayed.
​A switch statement is used to execute the appropriate function based on the user's choice.
​Option 0 exits the program with a thank-you message.
​If an incorrect number is entered, an error message is displayed.

​Conclusion:
​This program serves as an excellent practical example of how parallel arrays can be used to manage related data. Despite its simplicity, it covers most of the fundamental functionalities of a small library management system. Future improvements could involve using more advanced data structures like structs or classes to group each book's data into a single object, which would make the code even more efficient and easier to manage.
