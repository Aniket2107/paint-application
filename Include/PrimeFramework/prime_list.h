/**
 * \file        prime_list.h
 * \brief       Common implementation of double-linked lists.
 * \copyright   Copyright (c) 2014 <br> PhiRobotics Research Pvt Ltd
 * 
 * \par
 *  For licensing information, see the file 'LICENSE' in the root folder of
 *  this software module
 *
 * \author      Alexey Gerenkov <alexey.gerenkov@phi-robotics.com>
 * \author      Nick Dolganov <nick.dolganov@phi-robotics.com>
 *
 * Review status: No.
 *
 */

#ifndef PRIME_COMM_LIST_H_
#define PRIME_COMM_LIST_H_

/**
 *  \ingroup    core
 *  \defgroup   PF_LIST LIST
 *  @{
 *  
 *  \brief      Prime List
 *  \details
 */

#if (PF_LIST_DEBUG == 1)

/**
 * Makes the given node invalid.
 *
 * \param pNode pointer to the list node to be invalidated.
 */
    #define PF_LIST_NODE_INVALIDATE(pNode) ((pNode)->pNext = (pNode)->pPrev = (PFNode*)PF_NULL_PTR)

/**
 * Checks that the given node isn't in a specific list.
 *
 * \param pList pointer to the list.
 * \param pNode pointer to the list node.
 */
    #define PF_LIST_ASSERT_NOT_CONTAINS(pList,pNode) \
        do { \
            PFNode *pN; \
            PF_ASSERT_PTR(pList); \
            PF_ASSERT_PTR(pNode); \
            PF_LIST_FOREACH_NODE(pN, pList) { \
                PF_ASSERT(pN != (PFNode *)(pNode)); \
            } \
        } while (0)

/**
 * Make sure that the specified list is valid.
 *
 * \param pList pointer to list.
 */
    #define PHI_LIST_ASSERT_VALID(pList) \
        do { \
            PFNode *pN, *pPrev; \
            PF_ASSERT((pList)->head.pNext != PF_NULL_PTR); \
            PF_ASSERT((pList)->head.pPrev == PF_NULL_PTR); \
            PF_ASSERT((pList)->tail.pNext == PF_NULL_PTR); \
            PF_ASSERT((pList)->tail.pPrev != PF_NULL_PTR); \
            pPrev = &(pList)->head; \
            PF_LIST_FOREACH_NODE(pN, pList) \
            { \
                PF_ASSERT(pN->pPrev == pPrev); \
                pPrev = pN; \
            } \
            PF_ASSERT(pN == &(pList)->tail); \
        } while (0)
#else
    #define PF_LIST_NODE_INVALIDATE(pNode) do {} while (0)
    #define PF_LIST_ASSERT_NOT_CONTAINS(pList,pNode) do {} while (0)
    #define PHI_LIST_ASSERT_VALID(pList) do {} while (0)
#endif

/**
 * This structure represents a node for double linked (bi-directional) lists.
 */
typedef struct PFNodeStruct
{
    struct PFNodeStruct *pNext; /**< next node in the list */
    struct PFNodeStruct *pPrev; /**< previous node in the list */
} PFNode;
typedef PFNode * PFpNode;

/**
 * \brief Root structure of a bi-directional list of PFNode structs.
 *
 * Lists must be initialized with PF_LIST_INIT() before first use.
 */
typedef struct PFListStruct
{
    PFNode head; /**< list head */
    PFNode tail; /**< list tail */
} PFList;
typedef PFList * PFpList;

/**
 * Initialize a list.
 *
 * \param pList pointer to list.
 */
#define PF_LIST_INIT(pList) \
    do { \
        (pList)->head.pNext = (PF_C_TYPEOF_OR_PGENERIC((pList)->head.pNext)) &(pList)->tail; \
        (pList)->head.pPrev = PF_NULL_PTR; \
        (pList)->tail.pNext = PF_NULL_PTR; \
        (pList)->tail.pPrev = (PF_C_TYPEOF_OR_PGENERIC((pList)->tail.pPrev)) &(pList)->head; \
    } while (0)

/**
 * Checks whether the list is empty.
 *
 * \param pList pointer to the list.
 */
#define PF_LIST_IS_EMPTY(pList)  ( (PFpgeneric)((pList)->head.pNext) == (PFpgeneric)(&(pList)->tail) )

/**
 * Adds a node to the list's head.
 *
 * \param pList pointer to the list.
 * \param pNode pointer to a node.
 */
#define PF_LIST_ADDHEAD(pList,pNode) \
    do { \
        PF_LIST_ASSERT_NOT_CONTAINS((pList),(pNode)); \
        (pNode)->pNext = (pList)->head.pNext; \
        (pNode)->pPrev = (pList)->head.pNext->pPrev; \
        (pNode)->pNext->pPrev = (pNode); \
        (pNode)->pPrev->pNext = (pNode); \
    } while (0)

/**
 * Unlinks the node from the head of the list pList and returns it.
 *
 * \param pList pointer to the list.
 * \return pointer to the unlinked head, or PF_NULL_PTR in case of list is empty.
 */
PF_C_STATIC_INLINE PFNode *pfListHeadRemove(PFList *pList)
{
    PFNode *pNode;

    PF_ASSERT_PTR(pList);

    if (PF_LIST_IS_EMPTY(pList))
        return (PFNode *)PF_NULL_PTR;

    pNode = pList->head.pNext;
    pList->head.pNext = pNode->pNext;
    pNode->pNext->pPrev = &pList->head;

    PF_LIST_NODE_INVALIDATE(pNode);

    return pNode;
}

/**
 * Adds node to the list's tail.
 *
 * \param pList pointer to the list.
 * \param pNode pointer to a node.
 */
#define PF_LIST_ADDTAIL(pList,pNode) \
    do { \
        PF_LIST_ASSERT_NOT_CONTAINS((pList),(pNode)); \
        (pNode)->pNext = &(pList)->tail; \
        (pNode)->pPrev = (pList)->tail.pPrev; \
        (pNode)->pPrev->pNext = (pNode); \
        (pList)->tail.pPrev = (pNode); \
    } while (0)

/**
 * Unlinks the node from the tail of the list pList and returns it.
 *
 * \param pList pointer to list.
 * \return pointer to the unlinked tail, or PF_NULL_PTR in case of list is empty.
 */
PF_C_STATIC_INLINE PFNode *pfListTailRemove(PFList *pList)
{
    PFNode *pNode;

    PF_ASSERT_PTR(pList);

    if (PF_LIST_IS_EMPTY(pList))
        return (PFNode*)PF_NULL_PTR;

    pNode = pList->tail.pPrev;
    pList->tail.pPrev = pNode->pPrev;
    pNode->pPrev->pNext = &pList->tail;

    PF_LIST_NODE_INVALIDATE(pNode);
    return pNode;
}

/**
 * Inserts one given node before another given node in the list.
 *
 * \param pNode pointer to a node to be inserted.
 * \param pRef pointer to a reference node.
 */
#define PF_LIST_INSERT_BEFORE(pNode, pRef) \
    do { \
        PF_ASSERT_PTR(pNode); \
        PF_ASSERT_PTR(pRef); \
        (pNode)->pNext = (pRef); \
        (pNode)->pPrev = (pRef)->pPrev; \
        (pRef)->pPrev->pNext = (pNode); \
        (pRef)->pPrev = (pNode); \
    } while (0)

/**
 * Removes given node from the list it is in.
 *
 * \param pNode pointer to the node to be removed from the list.
 */
#define PF_LIST_REMOVE(pNode) \
    do { \
        PF_ASSERT_PTR(pNode); \
        (pNode)->pPrev->pNext = (pNode)->pNext; \
        (pNode)->pNext->pPrev = (pNode)->pPrev; \
        PF_LIST_NODE_INVALIDATE(pNode); \
    } while (0)

/**
 * Gets a pointer to the first node in the list or tail of the list if the list is empty.
 *
 * \param pList pointer to list.
 */
#define PF_LIST_HEAD(pList) ((pList)->head.pNext)

/**
 * Get a pointer to the last node in the list or head of the list if the list is empty.
 *
 * \param pList pointer to list.
 */
#define PF_LIST_TAIL(pList) ((pList)->tail.pPrev)

/** 
 * Runs for loop over all nodes in the list.
 *
 * \param pNode pointer to a list node where the pointer to the node of current iteration will be saved.
 * \param pList pointer to the list.
 *
 * \note This macro is not removal safe.
 */
#define PF_LIST_FOREACH_NODE(pNode, pList) \
    for( \
        (pNode) = (PF_C_TYPEOF_OR_PGENERIC(pNode))PF_LIST_HEAD(pList); \
        ((PFNode *)(pNode))->pNext; \
        (pNode) = (PF_C_TYPEOF_OR_PGENERIC(pNode))(((PFNode *)(pNode))->pNext) \
    )

/**
 * Runs removal save for() loop over all nodes in the list.
 *
 * \param pNode pointer to a list node where the pointer to the node of current iteration will be saved.
 * \param pIter pointer to a list node to store current iterator.
 * \param pList pointer to the list.
 */
#define PF_FOREACH_NODE_SAFE(pNode, pIter, pList) \
    for( \
        (pNode) = (PF_C_TYPEOF_OR_PGENERIC(pNode))PF_LIST_HEAD(pList), (pIter) = ((PFNode *)(pNode))->pNext; \
        ((PFNode *)(pNode))->pNext; \
        (pNode) = (pIter), (pIter) = (PF_C_TYPEOF_OR_PGENERIC(pNode))(((PFNode *)(pNode))->pNext) \
    )

/**
 * Runs for() loop over all nodes in the list in reverse order.
 *
 * \param pNode pointer to a list node where the pointer to the node of current iteration will be saved.
 * \param pList pointer to the list.
 */
#define PF_FOREACH_NODE_REVERSE(pNode, pList) \
    for( \
        (pNode) = (PF_C_TYPEOF_OR_PGENERIC(pNode))PF_LIST_TAIL(pList); \
        ((PFNode *)(pNode))->pPrev; \
        (pNode) = (PF_C_TYPEOF_OR_PGENERIC(pNode))(((PFNode *)(pNode))->pPrev) \
    )

/**
 * Runs removal safe for() loop over all nodes in the list in reverse order.
 *
 * \param pNode pointer to a list node where the pointer to the node of current iteration will be saved.
 * \param pIter pointer to a list node to store current iterator.
 * \param pList pointer to the list.
 */
#define PF_FOREACH_NODE_REVERSE_SAFE(pNode, pIter, pList) \
    for( \
        (pNode) = (PF_C_TYPEOF_OR_PGENERIC(pNode))PF_LIST_TAIL(pList), (pIter) = ((PFNode *)(pNode))->pPrev; \
        ((PFNode *)(pNode))->pPrev; \
        (pNode) = (pIter), (pIter) = (PF_C_TYPEOF_OR_PGENERIC(pNode))(((PFNode *)(pNode))->pPrev) \
    )

#endif /* PRIME_COMM_LIST_H_ */

/**@}*/
