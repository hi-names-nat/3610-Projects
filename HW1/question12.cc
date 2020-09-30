bool found = false;

seqSearch (const ElemTime& item, int n) const {
    if (list[n] == item) {
        found = true;
        break;
    }
    if (n > length) {
        return;
    }
    else seqSearch(item, n + 1)
}