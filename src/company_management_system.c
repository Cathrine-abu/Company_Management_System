#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "company_management_system.h"


/************************
 * Cathrine Abu-Elazam
 * 325516193
 * ex_5
 ************************/


// Print the menu
void menu ()
{
    printf("Welcome!\n"
           "Please select the desired option:\n"
           "1. Join the company\n"
           "2. Open a new project\n"
           "3. Join an existing project\n"
           "4. See what projects are in work\n"
           "5. See which people are in what projects\n"
           "6. Work on existing project\n"
           "7. Leave the company\n"
           "8. Exit\n"
           "Enter your choice:");
}

// Clear the input buffer
void clearInputBuffer(void)
{
    char c;
    while ((scanf("%c", &c)) == 1 && c != '\n'){

    }
}
/*
  The function reads characters one by one and allocates memory to build a string to hold the characters it reads
  and returns a pointer to a character array (string)
*/
char *getChars(void) {
    char *str = NULL;
    char c;
    int index = 0; // Index to track the current position in the string
    int capacity = 1; // Initial capacity of the string

    // Allocate memory for the string
    str = (char *)malloc(capacity * sizeof(char));
    if (str == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    scanf("%c", &c);
    // Read characters one by one until newline is encountered
    while (c != '\n') {
        // Check if more memory needs to be allocated
        if (index >= capacity) {
            capacity *= 2; // Double the capacity
            char *temp = (char *)realloc(str, capacity * sizeof(char));
            if (temp == NULL) {
                printf("Memory reallocation failed.\n");
                free(str); // Free the previously allocated memory
                exit(EXIT_FAILURE);
            }
            str = temp;
        }
        str[index] = c;
        index++;
        scanf("%c", &c);
    }

    // Allocate one more byte for the null terminator
    char *temp = (char *)realloc(str, (index + 1) * sizeof(char));
    if (temp == NULL) {
        printf("Memory reallocation failed.\n");
        free(str); // Free the previously allocated memory
        exit(EXIT_FAILURE);
    }
    str = temp;
    str[index] = '\0'; // Null-terminate the string

    return str;
}

// Check if worker Name exists
int isWorkerNameExists(Worker *workers[], int workerCount, const char *name)
{
    for (int i = 0; i < workerCount ; i++) {
        if(strcmp(workers[i]->name , name) == 0) // worker name exists return 1
        {
            return 1;

        }
    }
    return 0; //worker name does not exist return 0
}

// Check if project Name exists
int isProjectNameExists(Project *projects[], int projectCount, const char *name)
{
    for (int i = 0; i < projectCount ; i++) {
        if(strcmp(projects[i]->name , name) == 0) // worker name exists return 1
            return 1;
    }
    return 0; //worker name does not exist return 0
}

// Check if feature exists
int isFeatureExists(FeatureNode *head, const char *name)
{
    FeatureNode *current = head;
    while (current != NULL)
    {
        if (strcmp(current->feature, name) == 0)
            return 1; // feature exists return 1
        current = current->next;
    }
    return 0;// feature not exist return 0
}
// Print all workers name with numbers
void displayAllWorkersWithNumbers(Worker *workers[], int workerCount)
{
    for (int i = 0; i < workerCount; ++i) {
        printf("%d. %s\n", i + 1 ,workers[i]->name);
    }
}

// Print all projects name
void displayAllProjects(Project *projects[], int projectCount) {
    for (int i = 0; i < projectCount; ++i) {
        printf("%d. %s (Workers: %d)\n", i + 1, projects[i]->name, projects[i]->workerCount);
    }
}

// print all workers name with hyphen
void displayAllWorkersWithHyphen(Worker *workers[], int workerCount)
{
    for (int i = 0; i < workerCount; ++i) {
        printf("- %s\n",workers[i]->name);
    }
}

// Print workers that works in the project
void displayWorkersInProject(Worker *workers[], int workerCount)
{
    if(workerCount == 0)
    {
        printf(" There are no workers to display.\n");
        return;
    }
    else
    {
        for (int i = 0; i < workerCount; i++) {
            printf(" Worker: %s\n", workers[i]->name);
            printf("Projects this worker is involved in:\n");
            if(workers[i]->projectCount != 0)
            {
                for (int j = 0; j < workers[i]->projectCount; j++) {
                    printf("- %s\n", workers[i]->projects[j]->name);
                }
                printf("\n");
            }
            else
            {
                printf("Not involved in any projects.\n");
            }
        }
    }
}

// Print the features of the project
void displayFeature(FeatureNode *featureNode)
{
    FeatureNode *temp = featureNode;
    while (temp != NULL)
    {
        printf("- %s\n",temp->feature);
        temp = temp->next;
    }
}

// Print all the Existing projects
void displayAllWorkProjects(Project *projects[], int projectCount) {
    if(projectCount == 0)
    {
        printf(" There are no projects to display.\n");
        return;
    }
    else
    {
        for (int i = 0; i < projectCount; ++i) {
            printf(" Project: %s\n", projects[i]->name);
            printf("Workers in this project:\n");
            displayAllWorkersWithHyphen(projects[i]->workers,projects[i]->workerCount);
            printf("Features of the project:\n");
            if(projects[i]->features == NULL)
                printf("No features\n\n");
            else{
                displayFeature(projects[i]->features);
            }
        }
    }
}

// Display all projects for a specific worker
void displayWorkerProjects(Worker *worker[], int workerNum)
{
    for (int i = 0, j = 1; i < worker[workerNum]->projectCount; ++i, j++) {
        printf("%d. %s\n", j,worker[workerNum]->projects[i]->name);
    }
}

// Initializing the workers to NULL
void initNullWorkers (Worker *workers[])
{
    for (int i = 0; i < MAX_WORKERS; ++i) {
        workers[i] = NULL;
    }
}

// Initializing the projects to NULL
void initNullProjects (Project *projects[])
{
    for (int i = 0; i < MAX_PROJECTS; ++i) {
        projects[i] = NULL;
    }
}

// Add new project to projects array
void addNewProject(Worker *workers[], int workerCount, int numChoice, Project *newProject, int *projectCount
        ,Project *projects[])
{
    if (*projectCount < MAX_PROJECTS) {
        if (workerCount >= 0 && workerCount < MAX_WORKERS) {

            Worker *worker = workers[numChoice];

            Project  **temp = (Project **)realloc(worker->projects, (worker->projectCount + 1) *
                                                                    sizeof(Project *));
            if (temp == NULL) {
                printf("Memory allocation failed.\n");
                free(newProject->workers); // Free the allocated memory for workers array
                // free(newProject); // Free the allocated memory for the project
                exit(EXIT_FAILURE);
            }
            else{
                worker->projects = temp;
            }
            // Add the new project to the worker's list of projects
            worker->projects[worker->projectCount++] = newProject;
            projects[*projectCount] = newProject;
            (*projectCount)++;

        }
        else
        {
            printf("Invalid worker index.\n");
        }
    }
    else
    {
        printf("Maximum number of projects reached.\n");
    }
}

// Function that check if the worker involved in a project
int workOnProject(Worker *workers[], int workerCount)
{
    if(workers[workerCount]->projectCount == 0)
        return 0;
    return 1;
}

// Display the features of a project
int displayProjectFeatures(Project *project[], int numProject)
{
    int i = 1;
    FeatureNode *currentFeature =  project[numProject]->features;
    while (currentFeature != NULL)
    {
        printf("%d. %s\n", i, currentFeature->feature);
        i++;
        currentFeature = currentFeature->next;
    }
    return i - 1;
}

// Remove feature from a specific project
void removeFeatureFromProject(Project *project ,int numberFeature)
{
    // If we want to remove the first node
    if(numberFeature == FEATURE_NUM_ONE)
    {
        FeatureNode *temp = project->features;
        project->features = project->features->next;
        free(temp->feature);
        temp->feature = NULL;
        free(temp); // Free the memory of the removed node
        temp = NULL;
    }
        // If we want to remove the second node
    else if( numberFeature == FEATURE_NUM_TWO)
    {
        FeatureNode *temp = project->features->next;
        project->features->next = project->features->next->next;
        free(temp->feature);
        temp->feature = NULL;
        free(temp); // Free the memory of the removed node
        temp = NULL;
    }
        // If we want to remove other node
    else
    {
        FeatureNode *currentFeature = project->features;
        int i = 0;
        while ( numberFeature - FEATURE_NUM_TWO != i )
        {
            currentFeature = currentFeature->next;
            i++;
        }
        FeatureNode *temp = currentFeature->next;
        currentFeature->next = currentFeature->next->next;
        free(temp->feature);
        temp->feature = NULL;
        free(temp); // Free the memory of the removed node
        temp = NULL;
    }
}

// Create new node with the new feature
FeatureNode* createNode(char *newFeature)
{
    FeatureNode* newNode = (FeatureNode*) malloc(sizeof(FeatureNode));
    if( newNode == NULL)
    {
        printf("Memory allocation failed\n");
        free(newNode);
        exit(EXIT_FAILURE);
    }
    newNode->feature = newFeature;
    newNode->next = NULL;
    return newNode;
}

// Insert the new node that created
FeatureNode* insertNode(FeatureNode* head,char *newFeature)
{
    FeatureNode* newNode = createNode(newFeature);
    //If there are no features yet
    if(head == NULL)
        head = newNode;
    else
    {
        FeatureNode* current = head;
        while ( current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
    return head;
}

// Recursively free the features
void freeFeatures(FeatureNode *head)
{
    while (head != NULL) {
        FeatureNode *temp = head;
        head = head->next;
        free(temp->feature);
        temp->feature = NULL;
        free(temp);
        temp = NULL;
    }
}

// Add a worker to company
void joinCompany(Worker *workers[], int *workerCount)
{
    //Call the function to clear input buffer
    clearInputBuffer();
    char *workerName;
    printf(" Enter the name of the new worker: ");
    workerName = getChars();
    //The worker exists
    if(isWorkerNameExists(workers, *workerCount,workerName))
    {
        printf("A worker with this name already exists.\n"
               "There is not enough space in this company for both of us\n");
        free(workerName);
        workerName = NULL;
    }
        //The worker does not exist so add worker
    else
    {
        Worker *newWorker = (Worker *)malloc(sizeof(Worker));
        if (newWorker == NULL) {
            free(workerName);
            free(newWorker);
            exit(EXIT_FAILURE);
        }
        newWorker->name = workerName;
        newWorker->projects = NULL;
        newWorker->projectCount = 0;
        //Add new worker
        if (*workerCount < MAX_WORKERS) {
            workers[*workerCount] = newWorker;
            (*workerCount)++; // Increment the worker count

        }
        else {
            printf("The company is at full capacity.\n");
            free(workerName); // Free the allocated memory for the worker's name
            workerName = NULL;
            free(newWorker);  // Free the allocated memory for the worker structure
            newWorker = NULL;
        }
    }
}

// open a new project
void openNewProject(Worker *workers[], int workerCount, Project *projects[], int *projectCount)
{
    // we check the first index because we add workers In order from the beginning
    if(workers[0] == NULL)
    {
        printf(" There are no workers in the company yet, please join the company first.\n");
    }
        //When there is at least one worker
    else
    {
        int numChoice;
        printf(" Who are you? Choose a number:\n");
        displayAllWorkersWithNumbers(workers, workerCount);
        printf("Enter your choice: ");
        scanf("%d", &numChoice);
        //check that the user enter a number in the correct range
        if(numChoice > 0 && numChoice <=  workerCount )
        {
            clearInputBuffer(); //Call the function to clear input buffer
            char *projectName;
            printf(" Enter the name of the new project: ");
            projectName = getChars();

            // if the project exists
            if(isProjectNameExists ( projects, *projectCount ,projectName))
            {
                printf("A project with this name already exists.\n"
                       "better be more creative\n");
                free(projectName); // Free the allocated memory for the project name
                projectName = NULL;
            }
                //The project does not exist so add project
            else
            {
                Project *newProject = (Project *)malloc(sizeof(Project));
                if (newProject == NULL) {
                    free(projectName);
                    //  free(newProject);
                    exit(EXIT_FAILURE);
                }
                newProject->name = projectName;
                newProject->features = NULL;
                newProject->workers = (Worker **) malloc(MAX_WORKERS_IN_PROJECT * sizeof(Worker *));
                if (newProject->workers == NULL) {
                    free(projectName);
                    // free(newProject);
                    exit(EXIT_FAILURE);

                }
                newProject->workers[0] = workers[numChoice -1];
                newProject->workerCount=1;

                addNewProject(workers, workerCount ,numChoice - 1 , newProject, projectCount, projects);

                // Free the dynamically allocated memory for the project if it's not added to the list
                if (*projectCount >= MAX_PROJECTS) {
                    free(projectName);
                    free(newProject);
                }
            }
        }
        else
        {
            printf("you entered incorrect number\n");
        }
    }
}

// Add a worker to an existing project
void workerJoinsProject(Worker *workers[], int workerCount, Project *projects[], int projectCount)
{
    if(workerCount == 0)
        printf(" There are no workers in the company yet, please join the company first.\n");

    else if (projectCount == 0)
        printf(" There are no projects in the company yet, please create one first.\n");

    else
    {   int out = 0;// sign to exit case 3 and return to menu
        printf(" Select a worker to join a project:\n");
        displayAllWorkersWithNumbers(workers, workerCount);
        int workerNumChoice;
        printf("Enter the worker's number: ");
        scanf("%d",&workerNumChoice);

        // Check workerNumChoice validity
        if(workerNumChoice < 1 || workerNumChoice > workerCount)
        {
            printf("Invalid worker selection.\n");
            return;
        }
        printf(" Select a project to join:\n");
        displayAllProjects(projects, projectCount);
        int projectNum;
        printf("Enter the project's number: ");
        scanf("%d",&projectNum);

        // Check projectNum validity
        if(projectNum < 1 || projectNum > projectCount)
        {
            printf("Invalid project selection.\n");
            return;
        }        for (int i = 0; i < projects[projectNum -1]->workerCount; ++i) {
            if(strcmp(workers[workerNumChoice - 1]->name, projects[projectNum -1]->workers[i]->name) == 0)
            {
                printf("This worker is already part of the project '%s'\n", projects[projectNum - 1]->name);
                out = 1;
                break;
            }
        }
        if(out == 1) //to exist case 3 and return to the menu
            return;
        //add the worker to the project
        if(projects[projectNum - 1]->workerCount < MAX_WORKERS_IN_PROJECT)
        {
            int numCountWorkers = projects[projectNum - 1]->workerCount;
            projects[projectNum - 1]->workers[numCountWorkers]=workers[workerNumChoice - 1];

            Worker *worker = workers[workerNumChoice - 1];

            Project **temp = (Project **)realloc(worker->projects, (worker->projectCount + 1) *
                                                                   sizeof(Project *));
            if (temp == NULL) {
                printf("Memory reallocation failed.\n");
                free(worker->projects);
                exit(EXIT_FAILURE);
            } else {
                // Update worker->projects with the reallocated memory
                worker->projects = temp;
            }

            // Add the new project to the worker's list of projects
            worker->projects[worker->projectCount] = projects[projectNum - 1];
            (projects[projectNum - 1]->workerCount)++;
            (workers[workerNumChoice - 1]->projectCount)++;
        }
        else
            printf("Project is full.\n");
    }
}

// Add or remove feature from existing projects
void workOnExistingProject(Worker *workers[], int workerCount, int *projectCount, Project *projects[])
{
    if( workerCount == 0){
        printf(" There are no workers in the company yet, please join the company first.\n");
    }
    else if(projectCount == 0){
        printf(" There no projects in the company yet, please creat a project first.\n");
    }
        // there are workers in companies
    else
    {
        printf(" Select a worker:\n");
        displayAllWorkersWithNumbers(workers, workerCount);
        int workerNumberChoice;
        printf("Enter the worker's number: ");
        scanf("%d", &workerNumberChoice);

        if(workerNumberChoice < 1 || workerNumberChoice > workerCount)
        {
            printf("Invalid worker selection.\n");
            return;
        }
        //if the worker involves at least in one project
        if(workOnProject(workers, workerNumberChoice - 1))
        {
            printf(" Select a project:\n");
            displayWorkerProjects(workers, workerNumberChoice - 1);
            int projectNumChoice;
            printf("Enter the project number: ");
            scanf("%d", &projectNumChoice);

            if(projectNumChoice < 1 || projectNumChoice > workers[workerNumberChoice-1]->projectCount)
            {
                printf("Invalid project selection.\n");
                return;
            }

            printf("Do you want to add or remove a feature? (add/remove):");
            clearInputBuffer(); //Call the function to clear input buffer
            char *removeOrAdd;
            removeOrAdd = getChars();
            int length = strlen(removeOrAdd);
            // check if the last character is '\r' (carriage return)
            if(length > 0 && removeOrAdd[length-1] == '\r')
            {
                // set the last character to '\0'
                removeOrAdd[length-1] = '\0';
            }
            if(strcmp(removeOrAdd, "remove") == 0)
            {
                if(workers[workerNumberChoice - 1]->projects[projectNumChoice - 1]->features == NULL){
                    printf(" There are no features to remove.\n");
                    free(removeOrAdd);
                    removeOrAdd = NULL;
                    return;
                }
                    //There are at least one feature
                else
                {
                    int featureNumberChoice;
                    printf(" Select a feature to remove:\n");
                    int numFeatures = displayProjectFeatures(workers[workerNumberChoice - 1]->projects,
                                                             projectNumChoice - 1);
                    printf(" Enter your choice: ");
                    scanf("%d", &featureNumberChoice);
                    if(featureNumberChoice < 1 || featureNumberChoice > numFeatures)
                    {
                        printf("Invalid selection.\n");
                        free(removeOrAdd);
                        removeOrAdd = NULL;
                        return;
                    }
                    removeFeatureFromProject(workers[workerNumberChoice - 1]->projects[projectNumChoice - 1],
                                             featureNumberChoice);
                    free(removeOrAdd);
                    removeOrAdd = NULL;
                }
                return;
            }
            else if(strcmp(removeOrAdd, "add") == 0)
            {
                printf(" Enter the new feature: ");
                char *newFeature;
                newFeature = getChars();

                // If the feature exists
                if (isFeatureExists(projects[projectNumChoice - 1]->features,newFeature))
                {
                    printf("This feature already exists in the project.\n");
                    free(newFeature);
                    newFeature = NULL;

                    free(removeOrAdd);
                    removeOrAdd = NULL;

                    return;
                }
                FeatureNode* head = projects[projectNumChoice - 1]->features;
                FeatureNode* newHead = insertNode(head, newFeature);

                // Check if the new feature node was successfully inserted
                if (newHead != NULL) {
                    projects[projectNumChoice - 1]->features = newHead;


                } else {
                    printf("Failed to add the new feature.\n");
                    free(newFeature); // Free the memory allocated for the new feature
                    newFeature = NULL;
                }

                free(removeOrAdd);
                removeOrAdd = NULL;

                return;
            }
            else
            {
                printf("Invalid choice.\n");
                free(removeOrAdd);
                removeOrAdd = NULL;


            }
        }
            //the worker is not involved in any projects
        else
            printf("This worker is not involved in any projects.\n");

    }
}

// Function to free memory for a worker
void freeWorker(Worker *worker) {
    free(worker->name);
    free(worker->projects);
    free(worker);
}

// Function to free memory for a project
void freeProject(Project *project) {

    free(project->name);
    freeFeatures(project->features);
    free(project->workers);
    free(project);
}

// Free all memory allocation
void freeAllAllocations(Worker *workers[], int workerCount, Project *projects[], int projectCount)
{
    // Free memory associated with workers
    for (int i = 0; i < workerCount; ++i) {
        freeWorker(workers[i]);
    }
    // Free memory associated with projects
    for (int i = 0; i < projectCount; ++i) {
        freeProject(projects[i]);
    }

}

// Remove a worker that wants to leave the company
void leaveCompany(Worker *workers[], int *workerCount, Project *projects[], int *projectCount)
{
    if(*workerCount != 0)
    {
        printf(" Select a worker to leave the company:\n");
        displayAllWorkersWithNumbers(workers, *workerCount);
        int numWorkerChoice;
        printf("Enter the worker's number: ");
        scanf("%d", &numWorkerChoice);

        // Validate the worker choice
        if (numWorkerChoice >= 1 && numWorkerChoice <= *workerCount)
        {
            //Reduce the number of projects associated with the selected worker and eliminate any references to the worker
            Worker *chosenWorker = workers[numWorkerChoice - 1];
            for (int i = 0; i < chosenWorker->projectCount; ++i)
            {
                Project *currentProject = chosenWorker->projects[i];
                (currentProject->workerCount)--;

                // Remove worker reference from the project if it's the only worker
                if (currentProject->workerCount == 0)
                {
                    // Find and remove the project from the projects array
                    for (int j = 0; j < *projectCount; ++j)
                    {
                        if (projects[j] == currentProject)
                        {
                            freeFeatures(currentProject->features);
                            free(currentProject->name);
                            free(currentProject->workers);
                            free(currentProject);

                            // Shift projects array to fill the gap
                            for (int k = j; k < *projectCount - 1; ++k)
                            {
                                projects[k] = projects[k + 1];
                            }
                            projects[*projectCount -1] = NULL;
                            (*projectCount)--;
                            break;
                        }
                    }
                }
                    //If there are other workers in the project
                else
                {
                    for (int j = 0; j < currentProject->workerCount ; ++j) {
                        if(currentProject->workers[j] == chosenWorker || currentProject->workers[j] == NULL)
                        {
                            currentProject->workers[j] = currentProject->workers[j+1];
                            currentProject->workers[j+1] = NULL;
                        }
                    }
                }
            }

            free(chosenWorker->name);
            free(chosenWorker->projects);
            // Free memory associated with the chosen worker
            free(chosenWorker);

            // Shift workers array to fill the gap
            for (int i = numWorkerChoice - 1; i < *workerCount - 1; ++i)
            {
                workers[i] = workers[i + 1];
            }
            (*workerCount)--;
        }
        else
        {
            printf("Invalid worker selection.\n");
        }
    } else{
        printf(" There are no workers in the company yet, please join the company first.\n");
    }

}

int main() {
    Worker *workers[MAX_WORKERS];
    initNullWorkers(workers);
    Project *projects[MAX_PROJECTS];
    initNullProjects(projects);
    int workersNum = 0;
    int projectCount = 0;
    int numMenu ;
    menu();
    scanf("%d",&numMenu);

    while ( numMenu != EXIT)
    {
        switch (numMenu)
        {
            case JOIN_COMPANY_OPTION:
            {
                joinCompany(workers, &workersNum);
                break;
            }
            case OPEN_PROJECT_OPTION:
            {
                openNewProject(workers,workersNum,projects,&projectCount);
                break;
            }
            case JOIN_EXISTING_PROJECT_OPTION:
            {

                workerJoinsProject(workers, workersNum, projects, projectCount);
                break;
            }
            case SEE_WORK_PROJECTS:
            {
                displayAllWorkProjects(projects, projectCount);
                break;
            }
            case SEE_PEOPLE_IN_PROJECTS:
            {
                displayWorkersInProject(workers, workersNum);
                break;
            }
            case WORK_ON_EXISTING_PROJECT:
            {
                workOnExistingProject(workers, workersNum, &projectCount, projects);
                break;
            }
            case LEAVE_COMPANY:
            {
                leaveCompany(workers, &workersNum, projects, &projectCount);
                break;
            }
            default:
                printf("Invalid choice. Please try again.\n");
        }
        menu();
        scanf("%d",&numMenu);
    }
    freeAllAllocations(workers, workersNum, projects, projectCount);
    printf(" Exiting..."); // if numMenu is 8
    return  0;
}
