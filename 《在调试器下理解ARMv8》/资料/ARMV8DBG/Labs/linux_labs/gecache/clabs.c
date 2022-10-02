/*
Functions designed by Raymond to benchmark cache usage labs
*/
#include "clabs.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <intrin.h>
#else
#include <x86intrin.h>
#endif
FOO_DATA_S g_FooData[] = {
{	101	,"	Euterpe oleracea	"},
{	102	,"	Malpighia emarginata	"},
{	103	,"	Irvingia gabonensis	"},
{	104	,"	Garcinia livingstonei	"},
{	105	,"	Elaeis guineensis	"},
{	106	,"	Cornus × unalaschkensis	"},
{	107	,"	Spondias dulcis	"},
{	108	,"	Elaeis oleifera	"},
{	109	,"	Prunus americana	"},
{	110	,"	Prunus armeniaca	"},
{	111	,"	Mangifera pajang	"},
{	112	,"	Prunus maritima	"},
{	113	,"	Antidesma bunius	"},
{	114	,"	Mangifera caesia	"},
{	115	,"	Prunus serotina	"},
{	116	,"	Parajubaea torallyi	"},
{	117	,"	Syzygium australe	"},
{	118	,"	Dacryodes edulis	"},
{	119	,"	Cornus canadensis	"},
{	120	,"	Casimiroa edulis	"},
{	121	,"	Eugenia reinwardtiana	"},
{	122	,"	Byrsonima crassifolia	"},
{	123	,"	Prunus avium	"},
{	124	,"	Elaeagnus multiflora	"},
{	125	,"	Eugenia involucrata	"},
{	126	,"	Ziziphus mauritiana	"},
{	127	,"	Prunus virginiana	"},
{	128	,"	Chrysobalanus icaco	"},
{	129	,"	Cocos nucifera	"},
{	130	,"	Cornus mas	"},
{	131	,"	Terminalia catappa	"},
{	132	,"	Prunus rivularis	"},
{	133	,"	Empetrum nigrum	"},
{	134	,"	Murraya koenigii	"},
{	135	,"	Prunus domestica subsp. insititia	"},
{	136	,"	Phoenix dactylifera	"},
{	137	,"	Santalum acuminatum	"},
{	138	,"	Phyllanthus emblica	"},
{	139	,"	Owenia acidula	"},
{	140	,"	Litsea garciae	"},
{	141	,"	Syzygium fibrosum	"},
{	142	,"	Prunus umbellata	"},
{	143	,"	Gomortega keule	"},
{	144	,"	Prunus domestica subsp. italica	"},
{	145	,"	Buchanania obovata	"},
{	146	,"	Myrciaria floribunda	"},
{	147	,"	Terminalia ferdinandiana	"},
{	148	,"	Nephelium xerospermoides	"},
{	149	,"	Syzygium cumini	"},
{	150	,"	Butia capitata	"},
{	151	,"	Spondias purpurea	"},
{	152	,"	Ziziphus jujuba	"},
{	153	,"	Prunus salicina spp.	"},
{	154	,"	Cocos nucifera var. aurantiaca	"},
{	155	,"	Nephelium hypoleucum	"},
{	156	,"	Buchanania arborescens	"},
{	157	,"	Dimocarpus Longan	"},
{	158	,"	Litchi chinensis	"},
{	159	,"	Syzygium malaccense	"},
{	160	,"	Pouteria sapota	"},
{	161	,"	Mangifera indica	"},
{	162	,"	Bouea macrophylla	"},
{	163	,"	Sclerocarya birrea	"},
{	164	,"	Synsepalum dulcificum	"},
{	165	,"	Mauritia flexuosa	"},
{	166	,"	Prunus persica var. nucipersica	"},
{	167	,"	Azadirachta indica	"},
{	168	,"	Choerospondias axillaris	"},
{	169	,"	Myristica fragrans	"},
{	170	,"	Phyllanthus acidus	"},
{	171	,"	Prunus persica	"},
{	172	,"	Bunchosia glandulifera	"},
{	173	,"	Caryocar brasiliense	"},
{	174	,"	Coccoloba diversifolia	"},
{	175	,"	Canarium ovatum	"},
{	176	,"	Eugenia uniflora	"},
{	177	,"	Prunus domestica	"},
{	178	,"	Nephelium mutabile	"},
{	179	,"	Nephelium lappaceum	"},
{	180	,"	Syzygium suborbiculare	"},
{	181	,"	Syzygium luehmannii	"},
{	182	,"	Sageretia theezans	"},
{	183	,"	Serenoa repens	"},
{	184	,"	Lodoicea maldivica	"},
{	185	,"	Ardisia elliptica	"},
{	186	,"	Shepherdia argentea	"},
{	187	,"	Prunus spinosa	"},
{	188	,"	Mimusops elengi	"},
{	189	,"	Melicoccus bijugatus	"},
{	190	,"	Dialium indum	"},
{	191	,"	Dialium cochinchinense	"},
{	192	,"	Dialium guineense	"},
{	193	,"	Syzygium aqueum	"},
{	194	,"	Syzygium samarangense	"},
{	195	,"	Terminalia carpentariae	"},
{	196	,"	Manilkara kauki	"},
{	197	,"	Myrica rubra	"},
{	198	,"	Ximenia americana	"},
{	199	,"	Prunus domestica subsp. domestica	"},
};
GOO_DATA_S g_GooData[] = {
{	101	,"	Euterpe oleracea	"},
{	102	,"	Malpighia emarginata	"},
{	103	,"	Irvingia gabonensis	"},
{	104	,"	Garcinia livingstonei	"},
{	105	,"	Elaeis guineensis	"},
{	106	,"	Cornus × unalaschkensis	"},
{	107	,"	Spondias dulcis	"},
{	108	,"	Elaeis oleifera	"},
{	109	,"	Prunus americana	"},
{	110	,"	Prunus armeniaca	"},
{	111	,"	Mangifera pajang	"},
{	112	,"	Prunus maritima	"},
{	113	,"	Antidesma bunius	"},
{	114	,"	Mangifera caesia	"},
{	115	,"	Prunus serotina	"},
{	116	,"	Parajubaea torallyi	"},
{	117	,"	Syzygium australe	"},
{	118	,"	Dacryodes edulis	"},
{	119	,"	Cornus canadensis	"},
{	120	,"	Casimiroa edulis	"},
{	121	,"	Eugenia reinwardtiana	"},
{	122	,"	Byrsonima crassifolia	"},
{	123	,"	Prunus avium	"},
{	124	,"	Elaeagnus multiflora	"},
{	125	,"	Eugenia involucrata	"},
{	126	,"	Ziziphus mauritiana	"},
{	127	,"	Prunus virginiana	"},
{	128	,"	Chrysobalanus icaco	"},
{	129	,"	Cocos nucifera	"},
{	130	,"	Cornus mas	"},
{	131	,"	Terminalia catappa	"},
{	132	,"	Prunus rivularis	"},
{	133	,"	Empetrum nigrum	"},
{	134	,"	Murraya koenigii	"},
{	135	,"	Prunus domestica subsp. insititia	"},
{	136	,"	Phoenix dactylifera	"},
{	137	,"	Santalum acuminatum	"},
{	138	,"	Phyllanthus emblica	"},
{	139	,"	Owenia acidula	"},
{	140	,"	Litsea garciae	"},
{	141	,"	Syzygium fibrosum	"},
{	142	,"	Prunus umbellata	"},
{	143	,"	Gomortega keule	"},
{	144	,"	Prunus domestica subsp. italica	"},
{	145	,"	Buchanania obovata	"},
{	146	,"	Myrciaria floribunda	"},
{	147	,"	Terminalia ferdinandiana	"},
{	148	,"	Nephelium xerospermoides	"},
{	149	,"	Syzygium cumini	"},
{	150	,"	Butia capitata	"},
{	151	,"	Spondias purpurea	"},
{	152	,"	Ziziphus jujuba	"},
{	153	,"	Prunus salicina spp.	"},
{	154	,"	Cocos nucifera var. aurantiaca	"},
{	155	,"	Nephelium hypoleucum	"},
{	156	,"	Buchanania arborescens	"},
{	157	,"	Dimocarpus Longan	"},
{	158	,"	Litchi chinensis	"},
{	159	,"	Syzygium malaccense	"},
{	160	,"	Pouteria sapota	"},
{	161	,"	Mangifera indica	"},
{	162	,"	Bouea macrophylla	"},
{	163	,"	Sclerocarya birrea	"},
{	164	,"	Synsepalum dulcificum	"},
{	165	,"	Mauritia flexuosa	"},
{	166	,"	Prunus persica var. nucipersica	"},
{	167	,"	Azadirachta indica	"},
{	168	,"	Choerospondias axillaris	"},
{	169	,"	Myristica fragrans	"},
{	170	,"	Phyllanthus acidus	"},
{	171	,"	Prunus persica	"},
{	172	,"	Bunchosia glandulifera	"},
{	173	,"	Caryocar brasiliense	"},
{	174	,"	Coccoloba diversifolia	"},
{	175	,"	Canarium ovatum	"},
{	176	,"	Eugenia uniflora	"},
{	177	,"	Prunus domestica	"},
{	178	,"	Nephelium mutabile	"},
{	179	,"	Nephelium lappaceum	"},
{	180	,"	Syzygium suborbiculare	"},
{	181	,"	Syzygium luehmannii	"},
{	182	,"	Sageretia theezans	"},
{	183	,"	Serenoa repens	"},
{	184	,"	Lodoicea maldivica	"},
{	185	,"	Ardisia elliptica	"},
{	186	,"	Shepherdia argentea	"},
{	187	,"	Prunus spinosa	"},
{	188	,"	Mimusops elengi	"},
{	189	,"	Melicoccus bijugatus	"},
{	190	,"	Dialium indum	"},
{	191	,"	Dialium cochinchinense	"},
{	192	,"	Dialium guineense	"},
{	193	,"	Syzygium aqueum	"},
{	194	,"	Syzygium samarangense	"},
{	195	,"	Terminalia carpentariae	"},
{	196	,"	Manilkara kauki	"},
{	197	,"	Myrica rubra	"},
{	198	,"	Ximenia americana	"},
{	199	,"	Prunus domestica subsp. domestica	"},
};

FOO_DATA_S* GetFooByID(FOO_DATA_S* foos, int nUnits, int id)
{
    FOO_DATA_S* ret = NULL;
    for (int i = 0; i < nUnits; i++)
        if (foos[i].nIndex_ == id)
            return &foos[i];

    return ret;
}
GOO_DATA_S* GetGooByID(GOO_DATA_S* goos, int nUnits, int id)
{
    GOO_DATA_S* ret = NULL;
    for (int i = 0; i < nUnits; i++)
        if (goos[i].nIndex_ == id)
            return &goos[i];

    return ret;
}

int GeLabIntactInterlaceNoRef(int nLoops)
{
    printf("Cache lab to compare struct with names\n");
    int interesed_ids[] = { 1,101,188,2,5,88,66,155,133 };
    long long unsigned int start, end;
    long long unsigned int sum_foo = 0, sum_goo = 0;
    GOO_DATA_S* goo;
    FOO_DATA_S* foo;
    for (int l = 0; l < nLoops; l++)
    {
        for (int i = 0; i < sizeof(interesed_ids) / sizeof(interesed_ids[0]); i++)
        {
            start = __rdtsc();
            goo = GetGooByID(g_GooData, sizeof(g_GooData) / sizeof(g_GooData[0]), interesed_ids[i]);
            end = __rdtsc();
            sum_goo += end - start;

            start = __rdtsc();
            foo = GetFooByID(g_FooData, sizeof(g_FooData) / sizeof(g_FooData[0]), interesed_ids[i]);
            end = __rdtsc();
            sum_foo += end - start;

        }
    }
    printf("GeLabIntact: %d loops is done\n"
        "\tNonintact struct total %llu ticks aver %llu ticks\n"
        "\tIntact    struct total %llu ticks aver %llu ticks\n",
        nLoops, sum_foo, sum_foo / nLoops, sum_goo, sum_goo / nLoops
    );
}

int GeLabIntactInterlace(int nLoops)
{
    printf("Cache lab to compare struct with names\n");
    int interesed_ids[] = { 1,101,188,2,5,88,66,155,133 };
    long long unsigned int start, end;
    long long unsigned int sum_foo = 0, sum_goo = 0;
    long extern_ref = 0;
    GOO_DATA_S* goo;
    FOO_DATA_S* foo;
    for(int l =0;l< nLoops;l++)
    { 
        for (int i = 0; i < sizeof(interesed_ids)/sizeof(interesed_ids[0]); i++)
        {
            start = __rdtsc();
            goo = GetGooByID(g_GooData, sizeof(g_GooData) / sizeof(g_GooData[0]), interesed_ids[i]);
            if (goo)
                extern_ref += goo->szName_[0];
            end = __rdtsc();
            sum_goo += end - start;

            start = __rdtsc();
            foo = GetFooByID(g_FooData, sizeof(g_FooData) / sizeof(g_FooData[0]), interesed_ids[i]);
            if (foo)
                extern_ref += foo->szName_[0];
            end = __rdtsc();
            sum_foo += end - start;

        }
    }
    printf("GeLabIntact: %d loops is done\n"
        "\tNonintact struct total %llu ticks aver %llu ticks\n"
        "\tIntact    struct total %llu ticks aver %llu ticks\n",
        nLoops, sum_foo, sum_foo/ nLoops, sum_goo, sum_goo/ nLoops
    );
    return extern_ref; // to avoid code cutting by compiler
}

int GeLabIntactBatch(int nLoops)
{
    printf("Cache lab to compare struct with names\n");
    int interesed_ids[] = { 1,101,188,2,5,88,66,155,133,2,5,7,9,12,35,12,2,5 };
    long long unsigned int start, end;
    long long unsigned int sum_foo = 0, sum_goo = 0;
    long extern_ref = 0;
    GOO_DATA_S* goo;
    FOO_DATA_S* foo;
    for (int l = 0; l < nLoops; l++)
    {
        for (int i = 0; i < sizeof(interesed_ids) / sizeof(interesed_ids[0]); i++)
        {
            start = __rdtsc();
            foo = GetFooByID(g_FooData, sizeof(g_FooData) / sizeof(g_FooData[0]), interesed_ids[i]);
            if (foo)
                extern_ref += foo->szName_[0];
            end = __rdtsc();
            sum_foo += end - start;
        }
    }
    for (int l = 0; l < nLoops; l++)
    {
        for (int i = 0; i < sizeof(interesed_ids) / sizeof(interesed_ids[0]); i++)
        {
            start = __rdtsc();
            goo = GetGooByID(g_GooData, sizeof(g_GooData) / sizeof(g_GooData[0]), interesed_ids[i]);
            if (goo)
                extern_ref += goo->szName_[0];
            end = __rdtsc();
            sum_goo += end - start;
        }
    }
    printf("GeLabIntact: %d loops is done\n"
        "\tNonintact struct total %llu ticks aver %llu ticks\n"
        "\tIntact    struct total %llu ticks aver %llu ticks\n",
        nLoops, sum_foo, sum_foo / nLoops, sum_goo, sum_goo / nLoops
    );
    return extern_ref; // to avoid code cutting by compiler
}

#define likely(x)       __builtin_expect((x),1)
#define unlikely(x)     __builtin_expect((x),0)

int GeLabIntactBatchUnlikely(int nLoops)
{
    printf("Cache lab to compare struct with names\n");
    int interesed_ids[] = { 1,101,188,2,5,88,66,155,133,2,5,7,9,12,35,12,2,5 };
    long long unsigned int start, end;
    long long unsigned int sum_foo = 0, sum_goo = 0;
    long extern_ref = 0;
    GOO_DATA_S* goo;
    FOO_DATA_S* foo;
    for (int l = 0; l < nLoops; l++)
    {
        for (int i = 0; i < sizeof(interesed_ids) / sizeof(interesed_ids[0]); i++)
        {
            start = __rdtsc();
            foo = GetFooByID(g_FooData, sizeof(g_FooData) / sizeof(g_FooData[0]), interesed_ids[i]);
            if (unlikely(foo!=NULL))
                extern_ref += foo->szName_[0];
            end = __rdtsc();
            sum_foo += end - start;
        }
    }
    for (int l = 0; l < nLoops; l++)
    {
        for (int i = 0; i < sizeof(interesed_ids) / sizeof(interesed_ids[0]); i++)
        {
            start = __rdtsc();
            goo = GetGooByID(g_GooData, sizeof(g_GooData) / sizeof(g_GooData[0]), interesed_ids[i]);
            if (unlikely(goo!=NULL))
                extern_ref += goo->szName_[0];
            end = __rdtsc();
            sum_goo += end - start;
        }
    }
    printf("GeLabIntact: %d loops is done\n"
        "\tNonintact struct total %llu ticks aver %llu ticks\n"
        "\tIntact    struct total %llu ticks aver %llu ticks\n",
        nLoops, sum_foo, sum_foo / nLoops, sum_goo, sum_goo / nLoops
    );
    return extern_ref; // to avoid code cutting by compiler
}
