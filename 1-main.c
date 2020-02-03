#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * create_listint - Creates a doubly linked list from an array of integers
 *
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 *
 * Return: Pointer to the first element of the created list. NULL on failure
 */
listint_t *create_listint(const int *array, size_t size)
{
    listint_t *list;
    listint_t *node;
    int *tmp;

    list = NULL;
    while (size--)
    {
        node = malloc(sizeof(*node));
        if (!node)
            return (NULL);
        tmp = (int *)&node->n;
        *tmp = array[size];
        node->next = list;
        node->prev = NULL;
        list = node;
        if (list->next)
            list->next->prev = list;
    }
    return (list);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    listint_t *list;

    /*int array[] = {-5006566, 9698676, -3572726, -2238739, -2965688, -1813350, -7565313, 8708510, -6027364, -5035723, -4096851, -8535548, -525365, -1303813, 1412594, -1811608, -394184, 5336500, -5233795, 1599258, -1339986, -5441049, 2668350, 1944596, -4308884, -7520244, -3505811, 832831, -6849396, -6713550, 7855356, 3667378, 9999520, 6998245, 7278337, 7241551, -1912053, 9719127, 865575, -2559892, -6341400, 5895518, -8438018, -298768, -2083607, -4073003, 1511046, 1434048, 9401440, 1459816, 658945, -8137900, -5628589, -5791148, 5538895, 1116990};
*/
    /*int array[] = {559, 369, 801, 247, 424, 707, 474, 361, 455, 647, 874, 370, 890, 466, 347, 28, 820, 535, 470, 246, 437, 277, 641, 670, 129, 317, 636, 157, 662, 278, 907, 44, 844, 323, 728, 553, 103, 954, 783, 528, 267, 141, 797, 653, 800, 350, 155, 665, 833, 364, 20, 185, 850, 829, 86, 492, 631, 372, 699, 566, 381, 296, 793, 226, 955, 88, 813, 666, 68, 839, 498, 575, 39, 679, 632, 140, 779, 210, 685, 450, 951, 799, 329, 218, 913, 966, 606, 684, 355, 489, 877, 109, 977, 212, 245, 209, 513, 992, 431, 582, 454, 790, 878, 428, 358, 118, 263, 96, 318, 407, 448, 750, 552, 900, 482, 884, 561, 504, 211, 936, 465, 346, 98, 832, 365, 615, 688, 27, 389, 547, 174, 749, 78, 546, 223, 964, 182, 411, 580, 624, 443, 725, 649, 328, 307, 95, 268, 578, 518, 694, 521, 406, 183, 729, 432, 91, 26, 778, 240, 925, 691, 170, 143, 132, 203, 353, 200, 596, 803, 558, 436, 340, 789, 392, 77, 50, 471, 711, 714, 107, 715, 898, 169, 609, 217, 309, 22, 851, 427, 48, 391, 258, 594, 111, 970, 835, 59, 115, 475, 190, 145, 82, 500, 891, 991, 375, 754, 66, 293, 69, 591, 451, 305, 171, 999, 533, 289, 843, 794, 854, 192, 250, 550, 942, 425, 630, 701, 501, 17, 862, 542, 700, 30, 939, 598, 175, 583, 994, 612, 858, 669, 366, 114, 325, 442, 449, 34, 55, 887, 233, 122, 31, 46, 507, 452, 930, 846, 818, 523, 415, 338, 60, 167, 152, 148, 791, 36, 227, 331, 89, 626, 883, 727, 748, 298, 178, 726, 867, 668, 614, 377, 780, 139, 390, 708, 998, 853, 259, 330, 51, 186, 564, 177, 272, 885, 538, 817, 418, 747, 90, 687, 625, 131, 929, 555, 935, 673, 758, 493, 1000, 645, 567, 838, 941, 848, 527, 765, 782, 910, 736, 24, 124, 812, 447, 256, 7, 532, 224, 505, 401, 16, 610, 376, 321, 113, 579, 135, 102, 351, 208, 291, 918, 345, 733, 777, 635, 76, 161, 681, 972, 565, 638, 419, 537, 255, 570, 301, 656, 963, 539, 112, 308, 722, 965, 924, 299, 756, 886, 908, 15, 841, 244, 486, 526, 581, 613, 845, 133, 202, 286, 828, 108, 869, 339, 774, 53, 837, 738, 496, 876, 686, 710, 12, 746, 468, 499, 121, 294, 14, 735, 508, 473, 872, 865, 741, 980, 975, 99, 70, 593, 604, 402, 150, 100, 168, 360, 461, 768, 674, 960, 744, 25, 995, 257, 863, 600, 65, 706, 311, 434, 216, 882, 220, 856, 531, 409, 652, 788, 690, 314, 971, 516, 134, 893, 72, 664, 387, 37, 734, 506, 897, 917, 849, 648, 232, 753, 395, 230, 619, 889, 207, 912, 429, 63, 315, 356, 219, 379, 117, 195, 902, 383, 709, 282, 702, 743, 752, 47, 879, 864, 490, 896, 617, 695, 608, 260, 421, 946, 503, 497, 784, 759, 238, 536, 827, 93, 176, 441, 463, 201, 947, 196, 667, 384, 510, 962, 551, 831, 334, 10, 363, 836, 934, 522, 41, 228, 689, 445, 172, 611, 987, 928, 327, 616, 413, 6, 9, 852, 590, 657, 357, 704, 958, 199, 162, 627, 804, 101, 740, 639, 676, 462, 423, 205, 313, 868, 916, 956, 628, 931, 138, 127, 322, 179, 643, 18, 660, 592, 903, 926, 805, 204, 721, 644, 326, 881, 940, 416, 274, 253, 745, 396, 584, 61, 43, 478, 901, 985, 554, 979, 397, 164, 548, 762, 166, 33, 677, 459, 405, 989, 651, 716, 248, 483, 751, 457, 761, 577, 477, 997, 80, 302, 146, 755, 944, 540, 938, 344, 382, 957, 130, 814, 235, 563, 576, 97, 808, 54, 905, 920, 284, 153, 45, 894, 773, 515, 368, 847, 945, 23, 973, 698, 892, 285, 476, 159, 252, 3, 923, 587, 254, 239, 158, 283, 242, 495, 173, 292, 84, 821, 312, 658, 737, 571, 786, 953, 404, 909, 85, 125, 38, 225, 214, 104, 514, 899, 359, 771, 720, 42, 880, 637, 440, 623, 895, 809, 873, 332, 712, 655, 197, 288, 456, 629, 352, 573, 654, 494, 280, 265, 766, 767, 544, 693, 826, 300, 948, 367, 795, 136, 871, 568, 433, 243, 229, 261, 921, 595, 394, 646, 557, 815, 731, 875, 680, 692, 525, 414, 469, 435, 439, 472, 324, 840, 978, 757, 770, 993, 62, 241, 696, 914, 341, 792, 149, 860, 502, 724, 75, 144, 549, 974, 386, 249, 541, 420, 480, 262, 231, 281, 56, 742, 819, 787, 861, 996, 4, 71, 120, 572, 990, 986, 622, 830, 147, 180, 969, 524, 988, 276, 857, 49, 116, 237, 870, 165, 94, 488, 634, 151, 984, 430, 319, 919, 723, 123, 906, 188, 952, 342, 823, 866, 458, 703, 336, 335, 534, 137, 403, 467, 40, 269, 672, 206, 13, 380, 297, 222, 511, 333, 371, 310, 67, 398, 279, 273, 603, 181, 156, 640, 106, 618, 650, 52, 529, 485, 976, 191, 949, 961, 717, 320, 982, 316, 105, 683, 811, 562, 509, 119, 464, 950, 198, 802, 588, 491, 806, 855, 349, 785, 798, 426, 705, 904, 453, 621, 932, 79, 264, 763, 816, 348, 739, 807, 410, 834, 295, 287, 128, 184, 633, 73, 399, 764, 937, 888, 408, 266, 194, 560, 393, 251, 796, 354, 959, 32, 444, 517, 58, 589, 922, 306, 911, 154, 87, 607, 304, 968, 675, 775, 585, 718, 221, 659, 981, 487, 19, 519, 760, 378, 446, 373, 682, 769, 422, 543, 236, 599, 776, 642, 983, 388, 126, 824, 772, 2, 732, 374, 620, 81, 671, 512, 189, 163, 545, 92, 943, 933, 110, 29, 569, 160, 927, 605, 663, 362, 21, 822, 5, 8, 290, 343, 400, 215, 303, 484, 11, 275, 713, 234, 574, 187, 810, 697, 556, 842, 859, 967, 35, 412, 661, 915, 270, 825, 520, 719, 64, 57, 730, 74, 586, 530, 460, 83, 337, 385, 1, 271, 417, 479, 597, 481, 142, 601, 602, 781, 193, 678, 438, 213,174, 388, 19, 148, 735, 677, 353, 524, 185, 221, 766, 130, 819, 455, 867, 653, 117, 15, 692, 741, 559, 557, 140, 941, 474, 684, 215, 149, 715, 51, 647, 622, 374, 949, 469, 840, 313, 966, 897, 28, 449, 357, 233, 480, 311, 540, 919, 758, 490, 618, 615, 36, 902, 312, 829, 965, 97, 409, 5, 791, 496, 968, 187, 471, 630, 190, 989, 777, 566, 106, 619, 874, 488, 39, 934, 550, 828, 291, 790, 46, 52, 704, 894, 852, 207, 47, 59, 470, 624, 354, 856, 182, 600, 855, 775, 562, 749, 632, 495, 502, 806, 651, 960, 93, 798, 620, 345, 421, 792, 849, 871, 512, 327, 601, 957, 252, 522, 169, 905, 211, 680, 589, 363, 105, 970, 931, 166, 208, 784, 759, 268, 88, 980, 364, 127, 853, 277, 820, 74, 94, 181, 278, 78, 869, 865, 225, 655, 842, 603, 260, 483, 992, 854, 468, 895, 744, 824, 983, 391, 214, 537, 880, 248, 349, 739, 109, 458, 565, 77, 306, 640, 843, 681, 802, 7, 373, 797, 903, 987, 525, 195, 31, 781, 386, 663, 229, 440, 703, 446, 155, 160, 898, 595, 339, 570, 33, 344, 964, 453, 431, 779, 403, 751, 568, 769, 122, 432, 670, 807, 478, 736, 382, 249, 192, 289, 827, 746, 990, 926, 332, 625, 762, 76, 96, 816, 818, 240, 3, 588, 706, 906, 899, 811, 978, 163, 738, 423, 4, 682, 20, 770, 939, 716, 556, 780, 977, 356, 958, 752, 889, 634, 689, 683, 698, 755, 765, 113, 702, 255, 887, 21, 711, 213, 318, 270, 254, 250, 230, 475, 191, 786, 164, 416, 293, 646, 417, 314, 913, 286, 727, 787, 764, 481, 673, 956, 258, 162, 773, 947, 844, 200, 733, 352, 585, 509, 362, 116, 48, 518, 410, 73, 596, 812, 371, 508, 633, 85, 456, 996, 398, 590, 569, 70, 384, 484, 62, 493, 360, 223, 40, 204, 611, 835, 111, 463, 499, 159, 273, 379, 310, 872, 617, 660, 933, 25, 108, 430, 218, 234, 256, 397, 955, 330, 526, 212, 908, 343, 95, 146, 400, 993, 193, 24, 732, 402, 510, 282, 753, 376, 147, 83, 560, 896, 263, 932, 38, 515, 57, 847, 608, 810, 320, 198, 606, 479, 12, 652, 217, 334, 724, 986, 259, 321, 697, 84, 693, 442, 138, 426, 132, 533, 756, 434, 390, 754, 184, 267, 126, 882, 220, 323, 11, 503, 822, 242, 637, 292, 870, 243, 135, 129, 534, 959, 763, 723, 375, 98, 546, 448, 892, 904, 347, 32, 175, 425, 55, 937, 771, 58, 305, 532, 627, 466, 302, 275, 183, 998, 667, 914, 669, 863, 507, 648, 513, 731, 274, 81, 658, 921, 245, 228, 451, 994, 628, 946, 708, 368, 301, 858, 178, 572, 920, 170, 226, 331, 767, 86, 49, 688, 643, 760, 367, 44, 500, 981, 186, 64, 2, 558, 991, 948, 161, 202, 224, 831, 154, 875, 333, 517, 494, 406, 119, 825, 916, 461, 838, 582, 144, 439, 79, 506, 90, 380, 92, 65, 862, 785, 261, 928, 574, 539, 201, 952, 578, 988, 99, 271, 561, 54, 696, 972, 718, 984, 121, 668, 579, 621, 656, 172, 438, 602, 173, 56, 592, 71, 720, 110, 505, 657, 447, 91, 925, 516, 545, 171, 535, 701, 817, 337, 257, 997, 253, 322, 29, 298, 365, 408, 381, 459, 482, 50, 232, 498, 209, 383, 227, 179, 422, 614, 520, 598, 325, 597, 133, 424, 370, 284, 794, 722, 877, 413, 826, 974, 68, 973, 555, 583, 137, 304, 519, 609, 580, 707, 695, 851, 351, 82, 710, 976, 348, 205, 387, 411, 674, 571, 912, 359, 10, 599, 962, 80, 67, 392, 573, 814, 788, 910, 405, 890, 251, 971, 604, 238, 176, 231, 262, 235, 929, 900, 350, 272, 394, 486, 911, 131, 616, 527, 793, 850, 472, 467, 821, 141, 69, 491, 734, 358, 541, 623, 489, 115, 264, 372, 246, 177, 266, 222, 433, 445, 45, 650, 120, 795, 745, 326, 128, 465, 554, 420, 861, 726, 124, 721, 315, 834, 237, 487, 511, 156, 661, 194, 528, 789, 586, 9, 938, 953, 832, 626, 361, 299, 521, 935, 285, 501, 774, 53, 139, 531, 395, 927, 553, 642, 454, 100, 729, 587, 665, 485, 72, 102, 796, 477, 567, 641, 631, 799, 247, 329, 340, 881, 564, 737, 967, 576, 649, 730, 197, 719, 636, 443, 995, 346, 295, 803, 747, 860, 523, 594, 805, 750, 936, 180, 66, 848, 341, 142, 664, 328, 841, 982, 864, 296, 167, 366, 419, 504, 101, 985, 13, 30, 547, 846, 728, 529, 279, 612, 8, 575, 671, 317, 42, 150, 415, 34, 112, 309, 335, 290, 891, 27, 462, 885, 975, 678, 961, 63, 118, 969, 464, 610, 954, 288, 437, 679, 866, 530, 428, 324, 43, 276, 307, 691, 823, 1, 907, 654, 883, 924, 591, 104, 536, 418, 158, 675, 206, 473, 239, 743, 951, 593, 815, 548, 709, 772, 18, 297, 768, 37, 742, 280, 157, 450, 690, 338, 188, 168, 813, 444, 287, 355, 23, 319, 725, 429, 713, 857, 879, 659, 377, 552, 836, 801, 492, 859, 845, 549, 543, 6, 837, 404, 740, 940, 635, 435, 923, 316, 125, 16, 35, 107, 165, 60, 901, 414, 563, 236, 336, 644, 876, 662, 943, 613, 676, 283, 303, 123, 944, 629, 199, 14, 717, 427, 378, 300, 886, 216, 884, 809, 385, 605, 638, 514, 210, 714, 294, 134, 87, 189, 497, 457, 151, 830, 153, 963, 581, 782, 888, 639, 342, 909, 942, 412, 241, 369, 196, 396, 685, 1000, 114, 922, 917, 577, 893, 748, 783, 804, 551, 666, 17, 436, 61, 645, 873, 203, 687, 244, 878, 945, 999, 950, 401, 839, 542, 389, 694, 308, 22, 152, 808, 930, 833, 136, 705, 269, 918, 544, 607, 476, 103, 712, 761, 699, 265, 538, 776, 41, 700, 26, 89, 915, 75, 800, 979, 757, 868, 672, 686, 219, 584, 460, 407, 281, 143, 778, 393, 441, 145, 399, 452};*/
    int array[] = {1};
    size_t n = sizeof(array) / sizeof(array[0]);

    list = create_listint(array, n);
    if (!list)
        return (1);
    list->next = NULL;
    list->prev = NULL;
    print_list(list);
    printf("\n");
    insertion_sort_list(&list);
    printf("\n");
    print_list(list);
    return (0);
}
