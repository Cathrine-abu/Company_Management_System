
/************************
 * Cathrine Abu-Elazam
 * 325516193
 * ex_5
 ************************/

 #define MAX_WORKERS 50
 #define MAX_PROJECTS 100
 #define MAX_WORKERS_IN_PROJECT 4
 #define JOIN_COMPANY_OPTION 1
 #define OPEN_PROJECT_OPTION 2
 #define JOIN_EXISTING_PROJECT_OPTION 3
 #define SEE_WORK_PROJECTS 4
 #define SEE_PEOPLE_IN_PROJECTS 5
 #define WORK_ON_EXISTING_PROJECT 6
 #define LEAVE_COMPANY 7
 #define EXIT 8
 #define FEATURE_NUM_ONE 1 //I use it in remove feature function
 #define FEATURE_NUM_TWO 2 //I use it in remove feature function
 #define EXIT_FAILURE 1
 
 // Forward declarations
 typedef struct Worker Worker;
 typedef struct FeatureNode FeatureNode;
 typedef struct Project Project;
 
 struct Worker
 {
     char *name;
     Project **projects;
     int projectCount;
 };
 
 struct FeatureNode
 {
     char *feature;
     struct FeatureNode *next;
 };
 
 struct Project
 {
     char *name;
     Worker **workers;
     int workerCount;
     FeatureNode *features;
 };
 
 void menu ();
 void clearInputBuffer(void);
 char *getChars(void);
 int isWorkerNameExists(Worker *workers[], int workerCount, const char *name);
 int isProjectNameExists(Project *projects[], int projectCount, const char *name);
 int isFeatureExists(FeatureNode *head, const char *name);
 void displayAllWorkersWithNumbers(Worker *workers[], int workerCount);
 void displayAllProjects(Project *projects[], int projectCount);
 void displayAllWorkersWithHyphen(Worker *workers[], int workerCount);
 void displayWorkersInProject(Worker *workers[], int workerCount);
 void displayFeature(FeatureNode *featureNode);
 void displayAllWorkProjects(Project *projects[], int projectCount);
 void displayWorkerProjects(Worker *worker[], int workerNum);
 void initNullWorkers (Worker *workers[]);
 void initNullProjects (Project *projects[]);
 void addNewProject(Worker *workers[], int workerCount, int numChoice, Project *newProject, int *projectCount ,Project *projects[]);
 int workOnProject(Worker *workers[], int workerCount);
 int displayProjectFeatures(Project *project[], int numProject);
 void removeFeatureFromProject(Project *project ,int numberFeature);
 FeatureNode* createNode(char *newFeature);
 FeatureNode* insertNode(FeatureNode* head,char *newFeature);
 void freeFeatures(FeatureNode *head);
 void joinCompany(Worker *workers[], int *workerCount);
 void openNewProject(Worker *workers[], int workerCount, Project *projects[], int *projectCount);
 void workerJoinsProject(Worker *workers[], int workerCount, Project *projects[], int projectCount);
 void workOnExistingProject(Worker *workers[], int workerCount, int *projectCount, Project *projects[]);
 void freeWorker(Worker *worker);
 void freeProject(Project *project);
 void freeAllAllocations(Worker *workers[], int workerCount, Project *projects[], int projectCount);
 void leaveCompany(Worker *workers[], int *workerCount, Project *projects[], int *projectCount);
 