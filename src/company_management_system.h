// Constants for limits and menu options
#define MAX_WORKERS 50                    // Maximum number of workers in the system
#define MAX_PROJECTS 100                  // Maximum number of projects in the system
#define MAX_WORKERS_IN_PROJECT 4         // Maximum number of workers per project

// Menu option values
#define JOIN_COMPANY_OPTION 1            // Option to join the company
#define OPEN_PROJECT_OPTION 2            // Option to open a new project
#define JOIN_EXISTING_PROJECT_OPTION 3   // Option to join an existing project
#define SEE_WORK_PROJECTS 4              // Option to view all active projects
#define SEE_PEOPLE_IN_PROJECTS 5         // Option to view people in each project
#define WORK_ON_EXISTING_PROJECT 6       // Option to add features to a project
#define LEAVE_COMPANY 7                  // Option to leave the company
#define EXIT 8                           // Exit the program

// Constants used in feature removal
#define FEATURE_NUM_ONE 1                // Used in removeFeatureFromProject()
#define FEATURE_NUM_TWO 2                // Used in removeFeatureFromProject()

#define EXIT_FAILURE 1                   // Used to indicate failure in program execution

// Forward declarations of structs
typedef struct Worker Worker;
typedef struct FeatureNode FeatureNode;
typedef struct Project Project;

// Definition of Worker struct
struct Worker {
    char *name;              // Name of the worker
    Project **projects;      // Array of pointers to projects the worker is involved in
    int projectCount;        // Number of projects the worker is part of
};

// Definition of FeatureNode (linked list node for features)
struct FeatureNode {
    char *feature;           // Name/description of the feature
    struct FeatureNode *next; // Pointer to the next feature in the list
};

// Definition of Project struct
struct Project {
    char *name;              // Name of the project
    Worker **workers;        // Array of pointers to workers in the project
    int workerCount;         // Number of workers in the project
    FeatureNode *features;   // Linked list of project features
};

// Function declarations

// UI & Input
void menu();                                         // Display the main menu
void clearInputBuffer(void);                        // Clear the input buffer (stdin)
char *getChars(void);                               // Dynamically get string input from user

// Utility & Validation
int isWorkerNameExists(Worker *workers[], int workerCount, const char *name);       // Check if a worker already exists
int isProjectNameExists(Project *projects[], int projectCount, const char *name);   // Check if a project already exists
int isFeatureExists(FeatureNode *head, const char *name);                           // Check if a feature exists in the project

// Display functions
void displayAllWorkersWithNumbers(Worker *workers[], int workerCount);  // Display workers with numbering
void displayAllProjects(Project *projects[], int projectCount);         // Display all current projects
void displayAllWorkersWithHyphen(Worker *workers[], int workerCount);   // Display workers with hyphens
void displayWorkersInProject(Worker *workers[], int workerCount);       // Display which workers are in which projects
void displayFeature(FeatureNode *featureNode);                          // Print a single feature
void displayAllWorkProjects(Project *projects[], int projectCount);     // Display all active projects
void displayWorkerProjects(Worker *worker[], int workerNum);            // Show projects of a specific worker

// Initialization
void initNullWorkers(Worker *workers[]);           // Initialize worker array with NULLs
void initNullProjects(Project *projects[]);        // Initialize project array with NULLs

// Project management
void addNewProject(Worker *workers[], int workerCount, int numChoice,
                   Project *newProject, int *projectCount ,Project *projects[]);  // Add a new project
int workOnProject(Worker *workers[], int workerCount);                            // Let user select a project to work on
int displayProjectFeatures(Project *project[], int numProject);                   // Show features of a project
void removeFeatureFromProject(Project *project, int numberFeature);               // Remove a feature from a project

// Feature management
FeatureNode* createNode(char *newFeature);                        // Create a new feature node
FeatureNode* insertNode(FeatureNode* head, char *newFeature);     // Insert a new feature into the list
void freeFeatures(FeatureNode *head);                             // Free all feature nodes

// Main actions
void joinCompany(Worker *workers[], int *workerCount);                                    // Add a new worker
void openNewProject(Worker *workers[], int workerCount, Project *projects[], int *projectCount);  // Create a new project
void workerJoinsProject(Worker *workers[], int workerCount, Project *projects[], int projectCount); // Add worker to existing project
void workOnExistingProject(Worker *workers[], int workerCount, int *projectCount, Project *projects[]); // Add feature to a project

// Memory cleanup
void freeWorker(Worker *worker);                  // Free memory allocated to a worker
void freeProject(Project *project);               // Free memory allocated to a project
void freeAllAllocations(Worker *workers[], int workerCount, Project *projects[], int projectCount); // Free all dynamic memory

// Company management
void leaveCompany(Worker *workers[], int *workerCount, Project *projects[], int *projectCount); // Remove a worker and update projects
