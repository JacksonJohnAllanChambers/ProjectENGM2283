bool list::find(int item){

    bool result = false;
    for (node* ptr = start; ptr != NULL; ptr->next){
        if (item == ptr_>data) {
            result = true;
            break;
        }
    }
    return result
}
int list::size(void) {
    int count = 0;
    for (node* ptr = start; ptr != NULL; ptr->next){
        count++
    }
    return 0;
}