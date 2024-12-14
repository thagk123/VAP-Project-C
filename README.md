Περιγραφή Εργασίας
Αυτή η εργασία αφορά τη διαχείριση δεδομένων διαδρομών, όπως απόσταση, υψομετρικές διαφορές, χρόνο ταξιδιού, και άλλες παραμέτρους. Οι λειτουργίες επιτρέπουν την ταξινόμηση, αναζήτηση και αποθήκευση δεδομένων, με δυνατότητες ανάγνωσης από το αρχείο ή από την είσοδο του χρήστη.

Βασικές Λειτουργίες
Εκτύπωση Δεδομένων Διαδρομών:
Εμφάνιση διαδρομών με πληροφορίες όπως εκκίνηση, τερματισμός, μήκος, υψομετρικές διαφορές, και εκτιμώμενος χρόνος.

Αναζήτηση:
Αναζήτηση διαδρομών με βάση το μήκος, την τοποθεσία, ή το υψόμετρο.
Εύρεση διαδρομών με περισσότερη ανηφόρα ή κατηφόρα.

Ταξινόμηση:
Ταξινόμηση των διαδρομών κατά μήκος (φθίνουσα σειρά).

Αποθήκευση και Ανάγνωση:
Ανάγνωση δεδομένων από αρχείο.
Αποθήκευση ταξινομημένων δεδομένων σε αρχείο.

Περιγραφή Κλάσεων και Συναρτήσεων
struct route: Δομή που περιγράφει μια διαδρομή, με πεδία όπως:
ekk: Σημείο εκκίνησης.
term: Σημείο τερματισμού.
mikos: Μήκος διαδρομής.
ana: Υψομετρική ανάβαση.
kata: Υψομετρική κατάβαση.
meg: Μέγιστο υψόμετρο.
el: Ελάχιστο υψόμετρο.

Κύριες Συναρτήσεις
print1 και print2: Εκτύπωση διαδρομών με όλες τις πληροφορίες.
taksinomisi: Ταξινόμηση διαδρομών κατά μήκος.
readFromInput: Ανάγνωση δεδομένων διαδρομών από την είσοδο.
readFromFile: Ανάγνωση δεδομένων από αρχείο.
saveData: Αποθήκευση δεδομένων σε αρχείο.
findShort: Εύρεση διαδρομών με μήκος μικρότερο ή ίσο από συγκεκριμένη τιμή.
findLocation: Εύρεση διαδρομών που περιέχουν συγκεκριμένη τοποθεσία.
findAltitude: Εύρεση διαδρομών με υψόμετρο σε συγκεκριμένο εύρος.
findUpHill και findDownHill: Εύρεση διαδρομών με περισσότερη ανηφόρα ή κατηφόρα.
findTimely: Εύρεση διαδρομών που μπορούν να ολοκληρωθούν σε συγκεκριμένο χρόνο.




Project Description
This project manages route data, including distance, elevation changes, travel time, and other parameters. The functions allow sorting, searching, and saving data, with capabilities to read data from a file or user input.

Key Features

Route Data Display:
Show routes with details like starting point, destination, length, elevation changes, and estimated time.

Search:
Search for routes based on length, location, or elevation.
Find routes with more uphill or downhill sections.

Sorting:
Sort routes by length (in descending order).

Saving and Reading:
Read data from a file.
Save sorted data to a file.

Class and Function Descriptions
struct route: A structure representing a route, with fields like:
ekk: Starting point.
term: Ending point.
mikos: Route length.
ana: Uphill elevation.
kata: Downhill elevation.
meg: Maximum altitude.
el: Minimum altitude.

Main Functions
print1 and print2: Print route details.
taksinomisi: Sort routes by length.
readFromInput: Read route data from user input.
readFromFile: Read route data from a file.
saveData: Save data to a file.
findShort: Find routes shorter than or equal to a given length.
findLocation: Find routes containing a specific location.
findAltitude: Find routes within a specific altitude range.
findUpHill and findDownHill: Find routes with more uphill or downhill sections.
findTimely: Find routes that can be completed within a specific time.
